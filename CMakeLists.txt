cmake_minimum_required(VERSION 3.10)
project(cLab)

# specify the C standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(HelloCLab src/Hello.c)
add_executable(TestParameter src/TestParameter.c)
