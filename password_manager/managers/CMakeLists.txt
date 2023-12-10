cmake_minimum_required(VERSION 3.14)
project(cpp_nasm)
set (CMAKE_CXX_STANDARD 17)

set(CMAKE_ASM_NASM_OBJECT_FORMAT elf64)
set(CMAKE_ASM_NASM_LINK_EXECUTABLE "ld <CMAKE_ASM_NASM_LINK_FLAGS> <LINK_FLAGS> <OBJECTS>  -o <TARGET> <LINK_LIBRARIES>")
set(CMAKE_ASM_NASM_SOURCE_FILE_EXTENSIONS ${CMAKE_ASM_NASM_SOURCE_FILE_EXTENSIONS} s S)
enable_language(ASM_NASM)

set(ASM_SOURCE 
    asm/passwordCoder.s
    asm/passwordGenerator.s
)

set(OBJ_LIBS
    asm/passwordCoder.o
    asm/passwordGenerator.o
)

set_source_files_properties(${ASM_SOURCE} PROPERTIES LANGUAGE ASM_NASM)
add_executable(main 
            main.cpp 
            managers/encryptManager.cpp 
            managers/encryptManager.h 
            managers/dataManager.h 
            managers/dataManager.cpp 
            managers/passwordManager.h
            managers/passwordManager.cpp
            ${OBJ_LIBS}
)