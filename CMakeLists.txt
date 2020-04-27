cmake_minimum_required(VERSION 3.10)
project(cLab)
# specify the C standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

add_executable(HelloCLab src/Hello.c)
