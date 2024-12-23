#!/bin/sh
#build/tinylang-tblgen --gen-tokens -o TokenFilter.inc ./KeywordC.td
build/tinylang-tblgen --print-records ./KeywordC.td
