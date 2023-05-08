cmake_minimum_required(VERSION 3.24)
project(lab5 C)

set(CMAKE_C_STANDARD 11)

add_executable(lab5 main.c finder.c finder.h input.c input.h calk.c calk.h stack.h stack.c)
