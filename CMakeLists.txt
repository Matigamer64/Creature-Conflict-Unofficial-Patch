cmake_minimum_required(VERSION 3.15)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE "Release")

project(ccpatch)

add_library(ccpatch SHARED main.cpp)
set_target_properties(ccpatch PROPERTIES SUFFIX ".asi")
