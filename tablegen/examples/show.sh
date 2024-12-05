#!/bin/sh
P=~/build/llvm-project/llvm/lib/Target/X86
C=`pwd`
cd $P
llvm-tblgen ./X86.td -print-enums -class=Register
cd $C
