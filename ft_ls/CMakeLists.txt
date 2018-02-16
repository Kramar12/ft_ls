cmake_minimum_required(VERSION 3.9)
project(ft_ls C)

set(CMAKE_C_STANDARD 99)

add_executable(ft_ls ft_ls.h ft_ls.c major.c main.c auxiliary.c)