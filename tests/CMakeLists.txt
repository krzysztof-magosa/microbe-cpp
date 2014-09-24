find_package (Threads REQUIRED)

add_executable(sigmoid Sigmoid.cpp)
target_link_libraries (sigmoid microbe ${GTEST_LIBRARY} ${GTEST_LIBRARY_MAIN} ${CMAKE_THREAD_LIBS_INIT})
add_test(NAME sigmoid COMMAND sigmoid)

add_executable(tanh Tanh.cpp)
target_link_libraries (tanh microbe ${GTEST_LIBRARY} ${GTEST_LIBRARY_MAIN} ${CMAKE_THREAD_LIBS_INIT})
add_test(NAME tanh COMMAND tanh)

add_executable(neuron Neuron.cpp)
target_link_libraries (neuron microbe ${GTEST_LIBRARY} ${GTEST_LIBRARY_MAIN} ${CMAKE_THREAD_LIBS_INIT})
add_test(NAME neuron COMMAND neuron)

add_executable(biasNeuron BiasNeuron.cpp)
target_link_libraries (biasNeuron microbe ${GTEST_LIBRARY} ${GTEST_LIBRARY_MAIN} ${CMAKE_THREAD_LIBS_INIT})
add_test(NAME biasNeuron COMMAND biasNeuron)

add_executable(inputNeuron InputNeuron.cpp)
target_link_libraries (inputNeuron microbe ${GTEST_LIBRARY} ${GTEST_LIBRARY_MAIN} ${CMAKE_THREAD_LIBS_INIT})
add_test(NAME inputNeuron COMMAND inputNeuron)

add_executable(connection Connection.cpp)
target_link_libraries (connection microbe ${GTEST_LIBRARY} ${GTEST_LIBRARY_MAIN} ${CMAKE_THREAD_LIBS_INIT})
add_test(NAME connection COMMAND connection)

add_executable(normalizer Normalizer.cpp)
target_link_libraries (normalizer microbe ${GTEST_LIBRARY} ${GTEST_LIBRARY_MAIN} ${CMAKE_THREAD_LIBS_INIT})
add_test(NAME normalizer COMMAND normalizer)
