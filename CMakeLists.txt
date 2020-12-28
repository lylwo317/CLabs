cmake_minimum_required(VERSION 3.10)
project(cLab C CXX)

# specify the C standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS TRUE)
# 生成compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

#set(SDL2_INCLUDE_DIR "/home/kevin/CLionProjects/SDL/out/include/SDL")
IF (WIN32)
	MESSAGE(STATUS "Now is windows")
    #set(CMAKE_CXX_FLAGS_RELEASE "-Od ${CMAKE_CXX_FLAGS}")
	#STRING(REPLACE "-O2" "-Od" CMAKE_CXX_FLAGS_RELEASE ${CMAKE_CXX_FLAGS_RELEASE})
ELSEIF (APPLE)
	MESSAGE(STATUS "Now is Apple systens.")
ELSEIF (UNIX)
	include_directories("/home/kevin/CLionProjects/SDL/out/include/SDL" "/home/kevin/CLionProjects/SDL/out/include")
	link_directories("/home/kevin/glibc-2.31/out/lib" "/home/kevin/CLionProjects/SDL/out/lib" "/home/kevin/CLionProjects/CLabs/build")
	link_libraries(c)
	MESSAGE(STATUS "Now is UNIX-like OS's. Including aPPLE os x  and CygWin")

	add_executable(TestSds "src/string/TestSds.c" "src/string/sds.c" "src/string/zmalloc.c")
ENDIF ()

add_executable(HelloCLab src/Hello.c)
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

add_executable(TestConstructor src/cpp/TestConstructor.cpp)

add_executable(TestDestructor src/cpp/TestDestructor.cpp)

add_executable(TestInherit "src/cpp/TestInherit.cpp")
add_executable(TestInitializationList src/cpp/TestInitializationList.cpp)
add_executable(TestVirtual src/cpp/TestVirtual.cpp)
