#!/bin/bash
if [[ $# -eq 0 ]] ; then
    echo "Usage for callprofiler: $0 <function_name>"
    exit 1
fi
cd build
cmake -DCMAKE_CXX_COMPILER=clang++ ..
echo "[run] Configured CallProfiler"
make
echo "[run] Built CallProfiler"
clang -S -emit-llvm -O1 ../runtime/prog.c -o prog.ll
echo "[run] Compiled prog.c -> prog.ll"
opt --load-pass-plugin=CallProfiler.dylib --passes="callprofiler=$1" --stats prog.ll -o prog_instr.bc
echo "[run] Ran callprofiler pass for function $1"
llvm-dis prog_instr.bc
echo "[run] Turned binary into IR"
cat prog_instr.ll
