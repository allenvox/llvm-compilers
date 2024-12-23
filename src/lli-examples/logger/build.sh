#!/bin/sh

clang++ -c -o logger.o logger.cpp
clang++ -fPIC -shared -o logger.so logger.o

clang++ -S -emit-llvm prog.cpp 
