cmake_minimum_required(VERSION 3.10)
project(NeuralNetwork C)

set(CMAKE_C_STANDARD 99)

include_directories(${CMAKE_SOURCE_DIR}/include)
add_executable(neural_network src/main.c src/network.c src/matrix.c src/memtrack.c)
add_executable(test_matrix tests/test_matrix.c src/matrix.c src/memtrack.c)