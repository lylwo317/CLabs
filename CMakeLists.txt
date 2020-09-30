cmake_minimum_required(VERSION 3.10)
project(cLab C CXX)

# specify the C standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories("/home/kevin/CLionProjects/SDL/out/include/SDL" "/home/kevin/CLionProjects/SDL/out/include")
link_directories("/home/kevin/glibc-2.31/out/lib" "/home/kevin/CLionProjects/SDL/out/lib")
link_libraries(c)

add_executable(HelloCLab src/Hello.c)
add_executable(TestSds src/TestSds.c src/sds.c src/zmalloc.c)
add_executable(TestParameter src/TestParameter.c)

add_executable(TestSDL2 src/sdl2/TestSDL2.c)
target_link_libraries(TestSDL2 SDL2d)

add_executable(DisplayImage src/sdl2/DisplayImage.c)
target_link_libraries(DisplayImage SDL2d)

add_executable(TestStrFunction src/TestStringFunction.c)