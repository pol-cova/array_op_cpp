cmake_minimum_required(VERSION 3.23)
project(array_op_cpp)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(array_op_cpp
        exp3_arreglo_valor_mayor.cpp
        functions.h)
add_executable(optimizer exp3_optimized.cpp functions.h)
