#include "llvm/ADT/Statistic.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/PassManager.h"
#include "llvm/Passes/PassBuilder.h"
#include "llvm/Passes/PassPlugin.h"
#include "llvm/Support/Debug.h"
#include "llvm/IR/Module.h"

using namespace llvm;

#define DEBUG_TYPE "ppprofiler"

ALWAYS_ENABLED_STATISTIC(
    NumOfFunc, "Number of instrumented functions.");

namespace {
class PPProfilerIRPass
    : public llvm::PassInfoMixin<PPProfilerIRPass> {
public:
  llvm::PreservedAnalyses
  run(llvm::Module &M, llvm::ModuleAnalysisManager &AM);

private:
  int instrument(llvm::Function &F,
                  llvm::Function *EnterFn,
                  llvm::Function *ExitFn);
};
} // namespace

int PPProfilerIRPass::instrument(llvm::Function &F,
                                  Function *EnterFn,
                                  Function *ExitFn) {
  // NEW - Игнорировать функции, которые не имеют ровно двух аргументов
  if (F.arg_size() != 2)
    return 0;

  ++NumOfFunc;

  // Установить точку вставки в начало первого блока
  IRBuilder<> Builder(&*F.getEntryBlock().begin());

  // Создать глобальную строку для имени функции
  GlobalVariable *FnName =
      Builder.CreateGlobalString(F.getName());

  // Вызов __ppp_enter в начале функции
  Builder.CreateCall(EnterFn->getFunctionType(), EnterFn,
                     {FnName});

  // Найти все инструкции return и вызвать __ppp_exit перед ними
  for (BasicBlock &BB : F) {
    for (Instruction &Inst : BB) {
      if (Inst.getOpcode() == Instruction::Ret) {
        Builder.SetInsertPoint(&Inst);
        Builder.CreateCall(ExitFn->getFunctionType(),
                           ExitFn, {FnName});
      }
    }
  }
  return 1;
}

PreservedAnalyses
PPProfilerIRPass::run(Module &M,
                      ModuleAnalysisManager &AM) {
  // Do not instrument the runtime functions.
  if (M.getFunction("__ppp_enter") ||
      M.getFunction("__ppp_exit")) {
    return PreservedAnalyses::all();
  }

  // Create the function type and functions.
  Type *VoidTy = Type::getVoidTy(M.getContext());
  PointerType *PtrTy =
      PointerType::getUnqual(M.getContext());
  FunctionType *EnterExitFty =
      FunctionType::get(VoidTy, {PtrTy}, false);
  Function *EnterFn = Function::Create(
      EnterExitFty, GlobalValue::ExternalLinkage,
      "__ppp_enter", M);
  Function *ExitFn = Function::Create(
      EnterExitFty, GlobalValue::ExternalLinkage,
      "__ppp_exit", M);

  int counter = 0;
  // Call enter function.
  for (auto &F : M.functions()) {
    if (!F.isDeclaration() && F.hasName())
      counter += instrument(F, EnterFn, ExitFn);
  }
  return counter ? PreservedAnalyses::none() : PreservedAnalyses::all();;
}

void RegisterCB(PassBuilder &PB) {
  PB.registerPipelineParsingCallback(
      [](StringRef Name, ModulePassManager &MPM,
         ArrayRef<PassBuilder::PipelineElement>) {
        if (Name == "ppprofiler") {
          MPM.addPass(PPProfilerIRPass());
          return true;
        }
        return false;
      });
  PB.registerPipelineStartEPCallback(
      [](ModulePassManager &PM, OptimizationLevel Level) {
        PM.addPass(PPProfilerIRPass());
      });
}

llvm::PassPluginLibraryInfo getPPProfilerPluginInfo() {
  return {LLVM_PLUGIN_API_VERSION, "PPProfiler", "v0.1",
          RegisterCB};
}

#ifndef LLVM_PPPROFILER_LINK_INTO_TOOLS
extern "C" LLVM_ATTRIBUTE_WEAK ::llvm::PassPluginLibraryInfo
llvmGetPassPluginInfo() {
  return getPPProfilerPluginInfo();
}
#endif