cmake_minimum_required(VERSION 3.9)
project(ft_printf C)

set(CMAKE_C_STANDARD 99)
set(LIBFT ${CMAKE_SOURCE_DIR}/libft/libft.a)

add_executable(ft_printf main.c ft_printf.h num_flags.c ft_printf.c printhex.c flags.c auxiliary.c procwidth.c putsymb.c)
target_link_libraries(ft_printf ${LIBFT})