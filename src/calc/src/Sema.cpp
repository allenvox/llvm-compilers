#include "Sema.h"
#include "llvm/ADT/StringSet.h"
#include "llvm/Support/raw_ostream.h"

namespace {

    class DeclCheck : public ASTVisitor {
        llvm::StringSet<> Scope;
        bool HasError;

        enum ErrorType {
            Twice, Not
        };

        void error(ErrorType ET, llvm::StringRef V) {
          llvm::errs() << "Variable " << V << " "
                       << (ET == Twice ? "already" : "not")
                       << " declared\n";
          HasError = true;
        }

    public:
        DeclCheck() : HasError(false) {}

        bool hasError() { return HasError; }

        virtual void visit(Factor &Node) override {
          if (Node.getKind() == Factor::Ident) {
            if (Scope.find(Node.getVal()) == Scope.end())
              error(Not, Node.getVal());
          }
        }

        virtual void visit(BinaryOp &Node) override {
          if (Node.getLeft())
            Node.getLeft()->accept(*this);
          else
            HasError = true;
          if (Node.getRight())
            Node.getRight()->accept(*this);
          else
            HasError = true;
        }

        virtual void visit(WithDecl &Node) override {
          for (auto I = Node.begin(), E = Node.end(); I != E; ++I) {
            if (!Scope.insert(*I).second)
              error(Twice, *I);
          }
          if (Node.getExpr())
            Node.getExpr()->accept(*this);
          else
            HasError = true;
        }
    };

    class DeclUsageVisitor : public ASTVisitor {
        llvm::StringSet<> DeclaredVars;
        llvm::StringSet<> UsedVars;

    public:
        DeclUsageVisitor() {}

        void checkUnusedVars() {
          for (auto &Var: DeclaredVars) {
            if (UsedVars.find(Var.getKey()) == UsedVars.end()) {
              llvm::errs() << "Warning: Variable " << Var.getKey() << " declared but not used.\n";
            }
          }
        }

        virtual void visit(Factor &Node) override {
          // if identifier, add to UsedVars
          if (Node.getKind() == Factor::Ident) {
            UsedVars.insert(Node.getVal());
          }
        }

        virtual void visit(BinaryOp &Node) override {
          // recursively accept UsageVisitor in operands
          if (Node.getLeft()) {
            Node.getLeft()->accept(*this);
          }
          if (Node.getRight()) {
            Node.getRight()->accept(*this);
          }
        }

        virtual void visit(WithDecl &Node) override {
          // add all declared variables to DeclaredVars
          for (auto I = Node.begin(), E = Node.end(); I != E; ++I) {
            DeclaredVars.insert(*I);
          }
          // recursively accept UsageVisitor in expression
          if (Node.getExpr()) {
            Node.getExpr()->accept(*this);
          }
        }
    };
}

bool Sema::semantic(AST *Tree) {
  if (!Tree) {
    return false;
  }
  DeclCheck Check;
  Tree->accept(Check);
  DeclUsageVisitor UsageVisitor;
  Tree->accept(UsageVisitor);
  UsageVisitor.checkUnusedVars();
  return Check.hasError();
}
