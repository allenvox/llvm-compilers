#!/bin/bash

# Output assembly code
llc -o=bin/$1.s bin/$1.ll

# Compiles LLVM IR (bytecode) into assembly language for a specified architecture
llc -march=x86-64 -O3 -filetype=obj -relocation-model=pic -o=bin/$1.o bin/$1.ll

# Linking
clang -o bin/$1.x bin/$1.o src/rtcalc.c
