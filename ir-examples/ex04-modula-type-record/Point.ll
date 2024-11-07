; ModuleID = './Point.mod'
source_filename = "./Point.mod"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

%Point = type { i64, i64 }

@_t5Point1p = private global %Point

define void @_t5Point6Assign(i64 %x) {
entry:
  store i64 %x, ptr @_t5Point1p, align 8
  store i64 100, ptr getelementptr inbounds (%Point, ptr @_t5Point1p, i32 0, i32 1), align 8
  ret void
}
