cmake_minimum_required (VERSION 3.0)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
include_directories (include)
project (Microbe)

enable_testing ()

add_subdirectory (src)
add_subdirectory (examples)
add_subdirectory (tests)
