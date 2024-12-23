#include "llvm/ADT/Statistic.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/PassManager.h"
#include "llvm/Passes/PassBuilder.h"
#include "llvm/Passes/PassPlugin.h"
#include "llvm/Support/Debug.h"
#include "llvm/IR/Module.h"

using namespace llvm;

#define DEBUG_TYPE "callprofiler"

ALWAYS_ENABLED_STATISTIC(
    NumOfCalls, "Number of instrumented calls to the target function.");

namespace {
class CallProfilerIRPass
    : public llvm::PassInfoMixin<CallProfilerIRPass> {
  std::string TargetFunctionName;

public:
  CallProfilerIRPass(StringRef TargetName)
      : TargetFunctionName(TargetName) {}

  llvm::PreservedAnalyses
  run(llvm::Module &M, llvm::ModuleAnalysisManager &AM);

private:
  void instrument(Function &F, Function *CallEnterFn,
                  Function *CallExitFn, Function *TargetFn);
};
} // namespace

void CallProfilerIRPass::instrument(Function &F,
                                    Function *CallEnterFn,
                                    Function *CallExitFn,
                                    Function *TargetFn) {
  for (BasicBlock &BB : F) {
    for (Instruction &Inst : BB) {
      // Найти вызовы функций
      if (auto *Call = dyn_cast<CallInst>(&Inst)) {
        // Проверить, вызывается ли целевая функция
        if (Call->getCalledFunction() == TargetFn) {
          ++NumOfCalls;

          IRBuilder<> Builder(Call);

          // Создать глобальную строку для имени функции
          GlobalVariable *FnName =
              Builder.CreateGlobalString(TargetFn->getName());

          // Вызов __call_enter перед вызовом целевой функции
          Builder.CreateCall(CallEnterFn->getFunctionType(),
                             CallEnterFn, {FnName});

          // Вызов __call_exit после вызова целевой функции
          Builder.SetInsertPoint(Call->getNextNode());
          Builder.CreateCall(CallExitFn->getFunctionType(),
                             CallExitFn, {FnName});
        }
      }
    }
  }
}

PreservedAnalyses
CallProfilerIRPass::run(Module &M,
                        ModuleAnalysisManager &AM) {
  // Проверить, существует ли целевая функция
  Function *TargetFn = M.getFunction(TargetFunctionName);
  if (!TargetFn) {
    errs() << "Target function '" << TargetFunctionName
           << "' not found in the module.\n";
    return PreservedAnalyses::all();
  }

  // Создать функции __call_enter и __call_exit
  Type *VoidTy = Type::getVoidTy(M.getContext());
  PointerType *PtrTy =
      PointerType::getUnqual(M.getContext());
  FunctionType *EnterExitFty =
      FunctionType::get(VoidTy, {PtrTy}, false);
  Function *CallEnterFn = Function::Create(
      EnterExitFty, GlobalValue::ExternalLinkage,
      "__call_enter", M);
  Function *CallExitFn = Function::Create(
      EnterExitFty, GlobalValue::ExternalLinkage,
      "__call_exit", M);

  // Применить инструментирование для всех функций
  for (auto &F : M.functions()) {
    if (!F.isDeclaration() && F.hasName())
      instrument(F, CallEnterFn, CallExitFn, TargetFn);
  }

  return PreservedAnalyses::none();
}

// Регистрация прохода
void RegisterCB(PassBuilder &PB) {
  PB.registerPipelineParsingCallback(
      [](StringRef Name, ModulePassManager &MPM,
         ArrayRef<PassBuilder::PipelineElement>) {
        if (Name.startswith("callprofiler")) {
          StringRef TargetName = Name.substr(strlen("callprofiler="));
          MPM.addPass(CallProfilerIRPass(TargetName));
          return true;
        }
        return false;
      });
}

llvm::PassPluginLibraryInfo getCallProfilerPluginInfo() {
  return {LLVM_PLUGIN_API_VERSION, "CallProfiler", "v1.0",
          RegisterCB};
}

#ifndef LLVM_CALLPROFILER_LINK_INTO_TOOLS
extern "C" LLVM_ATTRIBUTE_WEAK ::llvm::PassPluginLibraryInfo
llvmGetPassPluginInfo() {
  return getCallProfilerPluginInfo();
}
#endif
