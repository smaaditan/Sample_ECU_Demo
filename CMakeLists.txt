cmake_minimum_required(VERSION 3.10)
project(sample_c_demo C)

if(USE_CLANG)
    set(CMAKE_C_COMPILER clang)
endif()

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_executable(sample_c_demo
    main.c
    a2l_generator.c
)
