cmake_minimum_required(VERSION 3.13)
project(z1)

set(CMAKE_CXX_STANDARD 14)

add_executable(z1 main.cpp minesboard.cpp minesboard.h MSBoardTextView.cpp MSBoardTextView.h MSTextController.cpp MSTextController.h)