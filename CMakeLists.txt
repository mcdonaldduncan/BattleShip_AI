cmake_minimum_required(VERSION 3.22)
project(Battleship)

include_directories(.)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -O2")

add_executable(app Battleship.cpp GameLogic.cpp)