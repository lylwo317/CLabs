set(CMAKE_ASM_NASM_SOURCE_FILE_EXTENSIONS nasm asm S)
set(CMAKE_NASM_LINK_EXECUTABLE "ld <LINK_FLAGS> <OBJECTS> -o <TARGET>")
# set(CMAKE_NASM_NASM_LINK_EXECUTABLE "nasm <OBJECTS> -o <TARGET> <LINK_LIBRARIES>")
set(CAN_USE_ASSEMBLER TRUE)
set(CMAKE_ASM_NASM_FLAGS "-g")#生成调试信息
# if (APPLE)
#     set(CMAKE_ASM_NASM_OBJECT_FORMAT macho64)
#     set(CMAKE_ASM_NASM_FLAGS "-DMACOS")
#     set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -macosx_version_min 10.13 -no_pie -L/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/lib")
# endif (APPLE)
# set( CMAKE_VERBOSE_MAKEFILE on)

if (UNIX AND NOT APPLE)
    set(CMAKE_ASM_NASM_OBJECT_FORMAT elf64)
endif (UNIX AND NOT APPLE)

enable_language(ASM_NASM)

add_executable(HelloNasm hello/hello.asm)
set_target_properties(HelloNasm PROPERTIES LINKER_LANGUAGE NASM)

add_executable(StackNasm stack/stack.asm)
set_target_properties(StackNasm PROPERTIES LINKER_LANGUAGE NASM)

# if (APPLE)
#     target_link_libraries(${project_name} System)
# endif (APPLE)