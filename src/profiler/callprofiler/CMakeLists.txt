cmake_minimum_required(VERSION 3.20.0)
project(callprofilerpass)

find_package(LLVM REQUIRED CONFIG)

message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")

list(APPEND CMAKE_MODULE_PATH ${LLVM_DIR})

include(AddLLVM)
include(HandleLLVMOptions)

include_directories("${LLVM_INCLUDE_DIR}")
add_definitions("${LLVM_DEFINITIONS}")

link_directories("${LLVM_LIBRARY_DIR}")

add_llvm_pass_plugin(CallProfiler MODULE CallProfiler.cpp)
