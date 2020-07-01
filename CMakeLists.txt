cmake_minimum_required(VERSION 3.15)
project(olimpiads)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g3")

add_definitions(-D_ONPC_ -D_GLIBCXX_DEBUG)

add_executable(olimpiads main.cpp)
