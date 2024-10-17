cmake_minimum_required(VERSION 3.29)
project(p2)

set(CMAKE_CXX_STANDARD 98)

add_executable(p2 main.cpp
        check_sudoku_board.c
        my_magic_square.c)
