#!/bin/sh

clang++ -S -emit-llvm ./ex.cpp
clang++  ./ex.cpp
