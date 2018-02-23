set(LIBFT ${CMAKE_SOURCE_DIR}/libft/libft.a)
set(FT_PRINTF ${CMAKE_SOURCE_DIR}/ft_printf/libftprintf.a)

find_library(OPENGL OpenGL)
find_library(APPKIT AppKit)

cmake_minimum_required(VERSION 3.9)
project(ft_ls C)

set(CMAKE_C_STANDARD 99)

add_executable(ft_ls ft_ls.h ft_ls.c major.c main.c mauxiliary.c rightstypes.c ls_sorts.c)

target_link_libraries(ft_ls ${LIBFT} ${FT_PRINTF})