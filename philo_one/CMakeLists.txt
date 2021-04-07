cmake_minimum_required(VERSION 3.12)
project(philo_one)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "-Wall -Werror -Wextra")

add_executable(philo_one
        philo_one.c
        utils.c
        utils_libft.c
        philo_one.h
        )
#target_compile_options(push_swap PRIVATE -Wall -Wextra -Werror)


