cmake_minimum_required(VERSION 3.10)
project(CLabs C CXX)
set(CMAKE_C_COMPILER "gcc")
set(CMAKE_CXX_COMPILER "g++")
# specify the C standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
#set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS TRUE)
# 生成compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(DEBUG_SDL2 FALSE)
set(DEBUG_GLIBC FALSE)
set(DEBUG_FFMPEG FALSE)
set(CMAKE_VERBOSE_MAKEFILE TRUE)

add_custom_target(
		copy-compile-commands ALL
		${CMAKE_COMMAND} -E copy_if_different
		${CMAKE_BINARY_DIR}/compile_commands.json
		${CMAKE_CURRENT_LIST_DIR}
)

#set(SDL2_INCLUDE_DIR "/home/kevin/CLionProjects/SDL/out/include/SDL")
IF (WIN32)
	MESSAGE(STATUS "Now is windows")
    #set(CMAKE_CXX_FLAGS_RELEASE "-Od ${CMAKE_CXX_FLAGS}")
	#STRING(REPLACE "-O2" "-Od" CMAKE_CXX_FLAGS_RELEASE ${CMAKE_CXX_FLAGS_RELEASE})
ELSEIF (APPLE)
	MESSAGE(STATUS "Now is Apple systems.")
	find_package(SDL)
	if (SDL2_FOUND)
		include_directories(${SDL2_INCLUDE_DIRS}/../)
	endif ()
	set(FFMPEG_HOME /usr/local/Cellar/ffmpeg/4.3.2_4)
	if (EXISTS ${FFMPEG_HOME})
		set(FFMPEG_FOUND TRUE)
	endif ()

	if (FFMPEG_FOUND)
		include_directories(${FFMPEG_HOME}/include)
		link_directories(${FFMPEG_HOME}/lib)
	endif ()
ELSEIF (UNIX)
	if (DEBUG_GLIBC)
        #添加debug版glibc链接路径
		set(GLIBC_LIB_DIR /home/kevin/glibc-2.31/out/lib)
		link_directories("${GLIBC_LIB_DIR}")
	endif ()

	if (DEBUG_SDL2)
        set(SDL2_HOME /home/kevin/CLionProjects/SDL/out)
		set(SDL2_INCLUDE_DIRS ${SDL2_HOME}/include)
		set(SDL2_LIB_DIRS ${SDL2_HOME}/lib)
		if (EXISTS ${SDL2_HOME})
			set(SDL2_FOUND TRUE)
		endif ()

		if (SDL2_FOUND)
			MESSAGE(STATUS "2SDL_FOUND.")
			include_directories(${SDL2_INCLUDE_DIRS})
			link_directories(${SDL2_LIB_DIRS})
			set(SDL2_LIBRARIES SDL2d)
		endif ()
	else()
		find_package(SDL2)
		if (SDL2_FOUND)
			MESSAGE(STATUS "SDL2_FOUND.")
			include_directories(${SDL2_INCLUDE_DIRS})
		endif ()
	endif ()

	if (DEBUG_FFMPEG)
        set(FFMPEG_HOME /home/kevin/CLionProjects/FFmpeg/out)
		include_directories("${FFMPEG_HOME}/include")
		link_directories("${FFMPEG_HOME}/lib")
	else()
	endif()

	link_libraries(c)
	MESSAGE(STATUS "Now is UNIX-like OS's. Including Linux  and CygWin")

	add_executable(TestSds "src/string/TestSds.c" "src/string/sds.c" "src/string/zmalloc.c")

	add_executable(memoryLayout src/memorylayout/MemoryLayout.c)
	#强制编译32位
	set_target_properties(memoryLayout PROPERTIES COMPILE_FLAGS "-m32" LINK_FLAGS "-m32")

	add_executable(TestEPoll src/net/TestEPoll.c)
ENDIF ()

add_executable(HelloC src/c/Hello.c)
add_executable(HelloCpp src/cpp/Hello.cpp)
add_executable(TestParameter src/c/TestParameter.c)
add_executable(TestStrFunction src/c/TestStringFunction.c)
add_executable(TestConstructor src/cpp/TestConstructor.cpp)
add_executable(TestDestructor src/cpp/TestDestructor.cpp)
add_executable(TestInherit src/cpp/TestInherit.cpp)
add_executable(TestInitializationList src/cpp/TestInitializationList.cpp)
add_executable(TestVirtual src/cpp/TestVirtual.cpp)
add_executable(TestPureVirtual src/cpp/TestPureVirtual.cpp)
add_executable(TestMultiInherit src/cpp/TestMultiInherit.cpp)
add_executable(TestVirtualInherit src/cpp/TestVirtualInherit.cpp)
add_executable(TestGodBolt src/cpp/TestGodBolt.cpp)
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
add_executable(TestTemplate src/cpp/template/TestTemplate.cpp)

add_executable(TestSelect src/net/TestSelect.c)
add_executable(TestPoll src/net/TestPoll.c)

if (SDL2_FOUND)
	add_executable(TestSDL2 src/sdl2/TestSDL2.c)
	target_link_libraries(TestSDL2 ${SDL2_LIBRARIES})

	add_executable(DisplayImage src/sdl2/DisplayImage.c)
	target_link_libraries(DisplayImage ${SDL2_LIBRARIES})

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
endif ()

add_executable(TestLogging src/base/noncopyable.cpp src/base/logging.cpp src/base/logstream.cpp src/base/main.cpp)
