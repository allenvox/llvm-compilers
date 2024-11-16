; ModuleID = './prog_instr.bc'
source_filename = "prog.c"
target datalayout = "e-m:o-p270:32:32-p271:32:32-p272:64:64-i64:64-i128:128-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx15.0.0"

@str = private unnamed_addr constant [6 x i8] c"Hello\00", align 1
@0 = private unnamed_addr constant [5 x i8] c"main\00", align 1

; Function Attrs: nofree nounwind ssp uwtable
define noundef i32 @main(i32 noundef %0, ptr nocapture noundef readnone %1) local_unnamed_addr #0 {
  call void @__ppp_enter(ptr @0)
  %3 = tail call i32 @puts(ptr nonnull dereferenceable(1) @str)
  call void @__ppp_exit(ptr @0)
  ret i32 0
}

; Function Attrs: nofree nounwind
declare noundef i32 @puts(ptr nocapture noundef readonly) local_unnamed_addr #1

declare void @__ppp_enter(ptr)

declare void @__ppp_exit(ptr)

attributes #0 = { nofree nounwind ssp uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="penryn" "target-features"="+cmov,+cx16,+cx8,+fxsr,+mmx,+sahf,+sse,+sse2,+sse3,+sse4.1,+ssse3,+x87" "tune-cpu"="generic" }
attributes #1 = { nofree nounwind }

!llvm.module.flags = !{!0, !1, !2, !3}
!llvm.ident = !{!4}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{i32 8, !"PIC Level", i32 2}
!2 = !{i32 7, !"uwtable", i32 2}
!3 = !{i32 7, !"frame-pointer", i32 2}
!4 = !{!"Homebrew clang version 18.1.8"}
