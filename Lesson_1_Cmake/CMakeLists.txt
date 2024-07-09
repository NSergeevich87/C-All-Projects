cmake_minimum_required(VERSION 3.10)

project(Lesson_1_Cmake) 

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(GameExecutable main.cpp start_game.cpp)