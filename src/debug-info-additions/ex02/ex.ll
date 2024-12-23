; ModuleID = './ex.cpp'
source_filename = "./ex.cpp"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-i128:128-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

%struct.Point = type { float, float }

; Function Attrs: mustprogress noinline nounwind optnone uwtable
define dso_local void @_Z4funcP5PointPfPiPc(ptr noundef %0, ptr noundef %1, ptr noundef %2, ptr noundef %3) #0 {
  %5 = alloca ptr, align 8
  %6 = alloca ptr, align 8
  %7 = alloca ptr, align 8
  %8 = alloca ptr, align 8
  store ptr %0, ptr %5, align 8
  store ptr %1, ptr %6, align 8
  store ptr %2, ptr %7, align 8
  store ptr %3, ptr %8, align 8

  %9 = load ptr, ptr %5, align 8
  %10 = getelementptr inbounds %struct.Point, ptr %9, i32 0, i32 0
  store float 0.000000e+00, ptr %10, align 4

  %11 = load ptr, ptr %5, align 8
  %12 = getelementptr inbounds %struct.Point, ptr %11, i32 0, i32 1
  store float 0.000000e+00, ptr %12, align 4

  %13 = load ptr, ptr %6, align 8
  store float 0.000000e+00, ptr %13, align 4

  %14 = load ptr, ptr %7, align 8
  store i32 0, ptr %14, align 4

  %15 = load ptr, ptr %8, align 8
  store i8 0, ptr %15, align 1

  ret void
}

attributes #0 = { mustprogress noinline nounwind optnone uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cmov,+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }

!llvm.module.flags = !{!0, !1, !2, !3, !4}
!llvm.ident = !{!5}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{i32 8, !"PIC Level", i32 2}
!2 = !{i32 7, !"PIE Level", i32 2}
!3 = !{i32 7, !"uwtable", i32 2}
!4 = !{i32 7, !"frame-pointer", i32 2}
!5 = !{!"Ubuntu clang version 18.1.3 (1ubuntu1)"}
