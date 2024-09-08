#!/bin/bash

# Optimizing LLVM IR
opt -O3 -S bin/$1.ll -o bin/$1_opt.ll

# Output
echo "$1.ll:"
cat bin/$1.ll
echo
echo
echo "$1_opt.ll:"
cat bin/$1_opt.ll
