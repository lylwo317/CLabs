cmake_minimum_required(VERSION 3.10)
project(CLabs C CXX)
#set(CMAKE_C_COMPILER "clang")
#set(CMAKE_CXX_COMPILER "clang++")
# specify the C standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED True)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
#clang -Xclang -fdump-record-layouts -stdlib=libc++ -c model.cc
#// 查看对象布局
#clang -Xclang -fdump-vtable-layouts -stdlib=libc++ -c model.cc
#// 查看虚函数表布局
#set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS TRUE)
# 生成compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(DEBUG_SDL2 FALSE)
set(DEBUG_GLIBC FALSE)
set(DEBUG_FFMPEG FALSE)
set(CMAKE_VERBOSE_MAKEFILE ON)

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
	find_package(SDL2)
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
	MESSAGE(STATUS "Now is UNIX-like OS's. Including Linux  and CygWin")
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
			MESSAGE(STATUS "SDL2_FOUND.")
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
ENDIF ()


# 添加子目录
ADD_SUBDIRECTORY(src/ffmpeg)
ADD_SUBDIRECTORY(src/sdl2)
ADD_SUBDIRECTORY(src/c)
ADD_SUBDIRECTORY(src/cpp)
ADD_SUBDIRECTORY(src/net)
ADD_SUBDIRECTORY(src/base)
ADD_SUBDIRECTORY(src/nasm)

IF (UNIX)
	MESSAGE(STATUS "Now is UNIX-like OS's. Including Linux  and CygWin")
	add_executable(TestSds "src/string/TestSds.c" "src/string/sds.c" "src/string/zmalloc.c")

	add_executable(memoryLayout src/memorylayout/MemoryLayout.c)
	#强制编译32位
	set_target_properties(memoryLayout PROPERTIES COMPILE_FLAGS "-m32" LINK_FLAGS "-m32")

	add_executable(TestEPoll src/net/TestEPoll.c)
ENDIF ()
