cmake_minimum_required(VERSION 3.10)
project(sample_cpp_demo)

# Force clang if requested
if(USE_CLANG)
    set(CMAKE_C_COMPILER clang)
    set(CMAKE_CXX_COMPILER clang++)
endif()

set(CMAKE_CXX_STANDARD 17)

add_executable(sample_cpp_demo
    sample_cpp_demo.cpp
    a2l_generator.cpp
)
