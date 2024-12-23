#!/bin/bash
cd build
cmake -DCMAKE_CXX_COMPILER=clang++ ..
echo "[run] Configured PPProfiler"
make
echo "[run] Built PPProfiler"
clang -S -emit-llvm -O1 ../runtime/prog_2args.c -o prog_2args.ll
echo "[run] Compiled prog_2args.c -> prog_2args.ll"
opt --load-pass-plugin=PPProfiler.dylib --passes="ppprofiler" --stats prog_2args.ll -o prog_2args_instr.bc
echo "[run] Ran ppprofiler pass"
llvm-dis prog_2args_instr.bc
echo "[run] Turned binary into IR"
cat prog_2args_instr.ll
