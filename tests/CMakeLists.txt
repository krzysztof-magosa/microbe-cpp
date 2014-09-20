find_package (Threads REQUIRED)

add_executable(sigmoid Sigmoid.cpp)
target_link_libraries (sigmoid microbe ${GTEST_LIBRARY} ${GTEST_LIBRARY_MAIN} ${CMAKE_THREAD_LIBS_INIT})
add_test(NAME sigmoid COMMAND sigmoid)

add_executable(tanh Tanh.cpp)
target_link_libraries (tanh microbe ${GTEST_LIBRARY} ${GTEST_LIBRARY_MAIN} ${CMAKE_THREAD_LIBS_INIT})
add_test(NAME tanh COMMAND tanh)
