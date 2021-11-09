if (SDL2_FOUND)
    add_executable(TestSDL2 TestSDL2.c)
    target_link_libraries(TestSDL2 ${SDL2_LIBRARIES})

    add_executable(DisplayImage DisplayImage.c)
    target_link_libraries(DisplayImage ${SDL2_LIBRARIES})
endif ()
