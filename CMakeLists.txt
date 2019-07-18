cmake_minimum_required(VERSION 3.14)
project(wolf3d C)

set(CMAKE_C_STANDARD 99)

file(GLOB SOURCES
        libft/*.h
        libft/*.c
        *.h
        *.c)
set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Wextra -Werror")

add_executable(wolf3d ${SOURCES} w_error.c w_validation.c w_initial.c w_readmap.c w_printmap.c w_hooks.c w_events.c w_sides.c w_drawcalc.c)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )
set(CMAKE_CXX_STANDARD 14)

find_library(libsdl SDL2)
find_library(libsdl_img SDL2_image)
find_library(libsdl_ttf SDL2_ttf)

target_link_libraries(wolf3d ${libsdl} ${libsdl_img} ${libsdl_ttf} "-framework OpenGL" "-framework AppKit")
