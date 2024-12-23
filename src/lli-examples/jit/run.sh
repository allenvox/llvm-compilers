#!/bin/sh

clang++ -S -emit-llvm ./main.cpp
./JIT main.ll
