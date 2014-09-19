cmake_minimum_required (VERSION 2.8.7)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_MACOSX_RPATH 1)
include_directories (include)
project (Microbe)

enable_testing ()

add_subdirectory (src)
add_subdirectory (examples)
add_subdirectory (tests)
