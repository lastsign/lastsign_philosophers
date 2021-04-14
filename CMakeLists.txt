cmake_minimum_required(VERSION 3.17.5)
project(Philosophers C)

set(CMAKE_C_STANDARD 99)

add_executable(philo_one philo_one/philo_one.c philo_one/utils.c philo_one/utils_libft.c)
add_executable(philo_two philo_two/philo_two.c philo_two/utils.c philo_two/utils_libft.c)
add_executable(philo_three philo_three/philo_three.c philo_three/utils.c philo_three/utils_libft.c)
