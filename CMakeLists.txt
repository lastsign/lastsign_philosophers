cmake_minimum_required(VERSION 3.19)
project(Philosophers C)

set(CMAKE_C_STANDARD 99)

add_executable(philo_one philo_one/philo_one.c philo_one/utils.c philo_one/utils_libft.c)add_executable(philo_one philo_one/philo_one.c philo_one/utils.c philo_one/utils_libft.c)
add_executable(philo_two philo_two/philo_two.c )