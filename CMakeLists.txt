cmake_minimum_required(VERSION 3.14)
project(wolf3d C)

set(CMAKE_C_STANDARD 99)

file(GLOB SOURCES
        libft/*.h
        libft/*.c
        *.h
        *.c)
set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Wextra -Werror")

add_executable(wolf3d ${SOURCES} w_error.c w_validation.c w_initial.c)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )
set(CMAKE_CXX_STANDARD 14)

find_library(libsdl SDL2)

target_link_libraries(wolf3d ${libsdl} "-framework OpenGL" "-framework AppKit")
