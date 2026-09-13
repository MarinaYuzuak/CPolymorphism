cmake_minimum_required(VERSION 3.19...3.25)
project(shapes C)

set(CMAKE_C_STANDARD 11)

add_executable(shapes src/main.c
        src/shape.c
        src/circle.c
        src/rectangle.c
        src/shape_vector.c)

target_include_directories(shapes PRIVATE include)
