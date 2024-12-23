; ModuleID = './array.mod'
source_filename = "./array.mod"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

@_t 10ExampleMod1v = private global [10 x i64]

define void @_t10ExampleMod4Main() {
entry:
  store i64 100, ptr getelementptr inbounds ([10 x i64], ptr @_t10ExampleMod1v, i32 0, i64 2), align 8
  ret void
}
