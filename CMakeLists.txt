cmake_minimum_required(VERSION 3.9)
project(SickLeaves)

set(CMAKE_CXX_STANDARD 11)

add_executable(SickLeaves main.cpp Employee.h Date.h SickLeave.h UserCredentials.h)