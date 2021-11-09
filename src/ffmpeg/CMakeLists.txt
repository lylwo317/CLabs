if (SDL2_FOUND)
    add_executable(SimplestVideoPlaySDL2 simplest_video_play_sdl2.cpp)
    target_link_libraries(SimplestVideoPlaySDL2 ${SDL2_LIBRARIES})

    add_executable(ffTutorial01 tutorial01.c)
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
