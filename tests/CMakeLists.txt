add_executable(sigmoid Sigmoid.cpp)
target_link_libraries (sigmoid microbe CppUTest)
add_test(NAME sigmoid COMMAND sigmoid)
