cmake_minimum_required(VERSION 3.8)
project(STL_Generator)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Vec3d.cpp Vec3d.h)
add_executable(STL_Generator ${SOURCE_FILES})