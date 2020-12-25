cmake_minimum_required(VERSION 3.10)
project(cLab C CXX)

# specify the C standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
# 生成compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

#set(SDL2_INCLUDE_DIR "/home/kevin/CLionProjects/SDL/out/include/SDL")

include_directories("/home/kevin/CLionProjects/SDL/out/include/SDL" "/home/kevin/CLionProjects/SDL/out/include")
link_directories("/home/kevin/glibc-2.31/out/lib" "/home/kevin/CLionProjects/SDL/out/lib" "/home/kevin/CLionProjects/CLabs/build")
link_libraries(c)

add_executable(HelloCLab src/Hello.c)
add_executable(TestSds "src/string/TestSds.c" "src/string/sds.c" "src/string/zmalloc.c")
add_executable(TestParameter src/TestParameter.c)

#add_executable(TestSDL2 src/sdl2/TestSDL2.c)
#target_link_libraries(TestSDL2 SDL2d)

#add_executable(DisplayImage src/sdl2/DisplayImage.c)
#target_link_libraries(DisplayImage SDL2d)

add_executable(TestStrFunction src/TestStringFunction.c)

add_executable(TestInt8 src/Int8Lab.c)

add_executable(HelloCpp src/Hello.cpp)

add_library(cal SHARED src/calculator/cal.c)

add_executable(TestCalInC src/calculator/testcalInC.c)
target_link_libraries(TestCalInC cal)

add_executable(TestCalInCpp src/calculator/testcalInCpp.cpp)
target_link_libraries(TestCalInCpp cal)

add_executable(TestNew src/cpp/TestNew.cpp)
