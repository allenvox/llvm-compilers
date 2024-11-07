; ModuleID = './array.mod'
source_filename = "./array.mod"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

define void @_t10ExampleMod4Main() {
entry:
  %0 = alloca [10 x i64], align 8
  %1 = getelementptr inbounds [10 x i64], ptr %0, i32 0, i64 0; x[0]
  store i64 3, ptr %1, align 8
  %2 = getelementptr inbounds ptr, ptr %0, i64 1 ; &v[1]
  %3 = load ptr, ptr %2, align 8  ; x = v[1]
  ret void
}
