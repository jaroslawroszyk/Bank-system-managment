cmake_minimum_required(VERSION 3.22)
project(BankSystemManagment)

set(CMAKE_CXX_STANDARD 20)

#include(cmake/GTest.cmake)
find_package(GTest REQUIRED)
include_directories()

include_directories(src)
add_subdirectory(src)
add_subdirectory(uts)
