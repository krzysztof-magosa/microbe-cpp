cmake_minimum_required (VERSION 2.8.7)

SET (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")

set(CMAKE_MACOSX_RPATH 1)
project (Microbe)

include(ExternalProject)
ExternalProject_Add(
    3rd_GTest
    URL https://googletest.googlecode.com/files/gtest-1.7.0.zip
    INSTALL_COMMAND ""
)

ExternalProject_Get_Property(3rd_GTest source_dir)
set(GTEST_INCLUDE_DIR ${source_dir}/include)

ExternalProject_Get_Property(3rd_GTest binary_dir)

set(GTEST_LIBRARY_PATH ${binary_dir}/${CMAKE_FIND_LIBRARY_PREFIXES}gtest.a)
set(GTEST_LIBRARY gtest)
add_library(${GTEST_LIBRARY} UNKNOWN IMPORTED)

set(GTEST_LIBRARY_MAIN_PATH ${binary_dir}/${CMAKE_FIND_LIBRARY_PREFIXES}gtest_main.a)
set(GTEST_LIBRARY_MAIN gtest_main)
add_library(${GTEST_LIBRARY_MAIN} UNKNOWN IMPORTED)

set_property(
    TARGET ${GTEST_LIBRARY} PROPERTY IMPORTED_LOCATION ${GTEST_LIBRARY_PATH}
)

set_property(
    TARGET ${GTEST_LIBRARY_MAIN} PROPERTY IMPORTED_LOCATION ${GTEST_LIBRARY_MAIN_PATH}
)

include_directories (
    include
    ${GTEST_INCLUDE_DIR}
)

add_dependencies(${GTEST_LIBRARY} 3rd_GTest)
add_dependencies(${GTEST_LIBRARY_MAIN} 3rd_GTest)

enable_testing ()

add_subdirectory (src)
add_subdirectory (examples)
add_subdirectory (tests)
