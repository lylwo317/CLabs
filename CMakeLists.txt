cmake_minimum_required(VERSION 3.10)
project(CLabs C CXX)
#set(CMAKE_C_COMPILER "gcc")
#set(CMAKE_CXX_COMPILER "g++")
# specify the C standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
#set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS TRUE)
# 生成compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(DEBUG_SDL FALSE)
set(DEBUG_GLIBC FALSE)
set(DEBUG_FFMPEG TRUE)

#set(SDL2_INCLUDE_DIR "/home/kevin/CLionProjects/SDL/out/include/SDL")
IF (WIN32)
	MESSAGE(STATUS "Now is windows")
    #set(CMAKE_CXX_FLAGS_RELEASE "-Od ${CMAKE_CXX_FLAGS}")
	#STRING(REPLACE "-O2" "-Od" CMAKE_CXX_FLAGS_RELEASE ${CMAKE_CXX_FLAGS_RELEASE})
ELSEIF (APPLE)
	MESSAGE(STATUS "Now is Apple systems.")
ELSEIF (UNIX)
	if (DEBUG_GLIBC)
        #添加debug版glibc链接路径
		set(GLIBC_LIB_DIR /home/kevin/glibc-2.31/out/lib)
		link_directories("${GLIBC_LIB_DIR}")
	endif ()

	if (DEBUG_SDL)
		set(SDL_INCLUDE_DIR /home/kevin/CLionProjects/SDL/out/include)
		set(SDL_LIB_DIR /home/kevin/CLionProjects/SDL/out/lib)
		include_directories("${SDL_INCLUDE_DIR}/SDL" "${SDL_INCLUDE_DIR}")
		link_directories("${SDL_LIB_DIR}")
		set(SDL2_LIBRARIES SDL2d)
	else()
		find_package(SDL2 REQUIRED)
		include_directories(${SDL2_INCLUDE_DIRS})
	endif ()

        if (DEBUG_FFMEPG)
            include_directories("/home/kevin/CLionProjects/FFmpeg/out/include")
            link_directories("/home/kevin/CLionProjects/FFmpeg/out/lib")
        else()
        endif()

	link_libraries(c)
	MESSAGE(STATUS "Now is UNIX-like OS's. Including Linux  and CygWin")

	add_executable(TestSds "src/string/TestSds.c" "src/string/sds.c" "src/string/zmalloc.c")
ENDIF ()

add_executable(HelloCLab src/Hello.c)
add_executable(TestParameter src/TestParameter.c)

add_executable(TestSDL2 src/sdl2/TestSDL2.c)
target_link_libraries(TestSDL2 ${SDL2_LIBRARIES})

add_executable(DisplayImage src/sdl2/DisplayImage.c)
target_link_libraries(DisplayImage ${SDL2_LIBRARIES})

add_executable(TestStrFunction src/TestStringFunction.c)

add_executable(TestInt8 src/Int8Lab.c)

add_executable(HelloCpp src/Hello.cpp src/student.cpp src/MyArray.cpp src/MyArray.h)

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
add_executable(TestPureVirtual src/cpp/TestPureVirtual.cpp)
add_executable(TestMultiInherit src/cpp/TestMultiInherit.cpp)
add_executable(TestVirtualInherit src/cpp/TestVirtualInherit.cpp)
add_executable(TestGodBolt src/cpp/TestGodBolt.cpp)
#add_executable(TestException src/exception/main.cpp)
add_executable(TestSingleton src/cpp/TestSingleton.cpp)
add_executable(TestOperator src/cpp/TestOperator.cpp)
add_executable(TestMove src/cpp/TestMove.cpp)
add_executable(TestForward src/cpp/TestForward.cpp)
add_executable(TestCast src/cpp/TestCast.cpp)
add_executable(TestLambda src/cpp/TestLambda.cpp)
add_executable(TestConst src/cpp/TestConst.cpp)
add_executable(TestConstexpr src/cpp/TestConstexpr.cpp)
add_executable(TestAuto src/cpp/TestAuto.cpp)
add_executable(TestDecltype src/cpp/TestDecltype.cpp)
add_executable(TestException src/cpp/TestException.cpp)
add_executable(TestSmartPointer src/cpp/TestSmartPointer.cpp)

add_executable(TestSelect src/net/TestSelect.c)
add_executable(TestPoll src/net/TestPoll.c)

add_executable(SimplestVideoPlaySDL2 src/ffmpeg/simplest_video_play_sdl2.cpp)
target_link_libraries(SimplestVideoPlaySDL2 ${SDL2_LIBRARIES})

add_executable(ffTutorial01 src/ffmpeg/tutorial01)
target_link_libraries(ffTutorial01
    ${SDL2_LIBRARIES}
    avcodec
    avdevice
    avfilter
    avformat
    avutil
    swresample
    swscale)

add_executable(memoryLayout src/memorylayout/MemoryLayout.c)
#强制编译32位
set_target_properties(memoryLayout PROPERTIES COMPILE_FLAGS "-m32" LINK_FLAGS "-m32")

add_executable(TestLogging src/base/noncopyable.cpp src/base/logging.cpp src/base/logstream.cpp src/base/main.cpp)
