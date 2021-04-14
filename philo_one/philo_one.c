/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptycho <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 19:14:00 by ptycho            #+#    #+#             */
/*   Updated: 2021/04/01 19:14:00 by ptycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "philo_one.h"

int		ft_atoi(const char *str)
{
	int	n;
	int		i;

	i = 0;
	n = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + (str[i] - '0');
		i++;
	}
	return (n);
}


int	ft_isdigit(int ch)
{
	if (ch >= '0' && ch <= '9')
		return (1);
	return (0);
}

void	an_exception(void)
{
	write(1, "Error\n", 6);
	exit(0);
}

void	check_argums(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				an_exception();
			j++;
		}
		i++;
	}
}

int		get_info_from_argum(int argc, char **argv, t_state *state)
{
	pthread_mutex_t death;
	pthread_mutex_t out;
	pthread_mutex_t stat;

	pthread_mutex_init(&death, NULL);
	pthread_mutex_init(&out, NULL);
	pthread_mutex_init(&stat, NULL);
	state->is_died = 0;
	state->num_philo = ft_atoi(argv[1]);
	state->time_die = ft_atoi(argv[2]);
	state->time_eat = ft_atoi(argv[3]);
	state->time_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		state->must_eat = ft_atoi(argv[5]);
	else
		state->must_eat = -1;
	if (!state->num_philo || !state->time_die || !state->time_eat || !state->time_sleep || !state->must_eat)
		return (0);
	state->death = death;
	state->out = out;
	state->stat = stat;
//	pthread_mutex_destroy(&death);
//	pthread_mutex_destroy(&out);
//	pthread_mutex_destroy(&stat);
	return (1);
}

void 	enjoy_write(char *mes, t_philo *philo)
{
	char 	*print_id;
	char 	*print_str_time;

	print_id = ft_itoa(philo->id + 1);
	print_str_time = ft_itoa(get_current_time() - philo->meal_start);
	if (!print_id || !print_str_time)
		return ;
	if (!philo->state->is_died)
	{
		write(1, print_str_time, ft_strlen(print_str_time));
		write(1, " ", 1);
		write(1, print_id, ft_strlen(print_id));
		write(1, mes, ft_strlen(mes));
	}
	free(print_id);
	free(print_str_time);
}

void 	print_stat(char *mes, t_philo *philo)
{
	pthread_mutex_lock(&philo->state->out);
	enjoy_write(mes, philo);
	pthread_mutex_unlock(&philo->state->out);
}

void 	*check_mortality(void* stat)
{
	t_philo *philo;

	philo = (t_philo *)stat;
	while (1)
	{
		pthread_mutex_lock(&philo->state->stat);
		if (get_current_time() - philo->meal_last > philo->state->time_die)
			break ;
		pthread_mutex_unlock(&philo->state->stat);
		usleep(10);
	}
	pthread_mutex_unlock(&philo->state->stat);
	if (!philo->state->must_eat)
		return (NULL);
	print_stat(" is died\n", philo);
	philo->state->is_died = 1;
	pthread_mutex_unlock(&philo->state->death);
	return (NULL);
}

void	enjoy_fork(t_philo *philo, int fl, int fr)
{
	pthread_mutex_lock(&philo->state->forks[fl]);
	print_stat(" has taken a fork\n", philo);
	pthread_mutex_lock(&philo->state->forks[fr]);
	print_stat(" has taken a fork\n", philo);
}


void 	enjoy_sleep(int time_todo)
{
	long 	start_sleep;

	start_sleep = get_current_time();
	while (get_current_time() - start_sleep < time_todo)
		usleep(10);
}


void	enjoy_meal(t_philo *philo)
{
	int 	l;
	int 	r;

	l = philo->id;
	r = (philo->id + 1) % philo->state->num_philo;
	if (philo->id % 2 == 0)
		enjoy_fork(philo, l, r);
	else
		enjoy_fork(philo, r, l);
	print_stat(" is eating\n", philo);
	pthread_mutex_lock(&philo->state->stat);
	philo->meal_last = get_current_time();
	pthread_mutex_unlock(&philo->state->stat);
	enjoy_sleep(philo->state->time_eat);
	pthread_mutex_unlock(&philo->state->forks[r]);
	pthread_mutex_unlock(&philo->state->forks[l]);
}


void 	*start_simulation(void *stat)
{
	t_philo *philo;
	pthread_t death;

	philo = (t_philo *)stat;
	philo->meal_start = get_current_time();
	philo->meal_last = get_current_time();
	pthread_create(&death, NULL, check_mortality, philo);
	while (philo->must_eat)
	{
		if (philo->state->is_died)
			break ;
		enjoy_meal(philo);
		if (philo->state->is_died)
			break ;
		print_stat(" is sleeping\n", philo);
		enjoy_sleep(philo->state->time_sleep);
		if (philo->state->is_died)
			break ;
		print_stat(" is thinking\n", philo);
		philo->must_eat--;
	}
	pthread_join(death, NULL);
	return (NULL);
}

void 	init_philo(t_state *state)
{
	int 			i;
	pthread_mutex_t fork[state->num_philo];
	t_philo 		philo[state->num_philo];
	pthread_t		pthread[state->num_philo];

	i = -1;
	state->forks = fork;
	while (++i < state->num_philo)
	{
		philo[i].id = i;
		philo[i].state = state;
		philo[i].must_eat = state->must_eat;
		pthread_create(&pthread[i], NULL, start_simulation, &philo[i]);
	}
	i = -1;
	while (++i < state->num_philo)
		pthread_join(pthread[i], NULL);
	i = -1;
	while (++i < state->num_philo)
		pthread_mutex_destroy(&state->forks[i]);
}

int		main(int argc, char **argv)
{
	t_state		state;
	if (argc == 5 || argc == 6)
	{
		check_argums(argc, argv);
		if (!get_info_from_argum(argc, argv, &state))
		{
			write(1, "Wrong arguments\n", 16);
			return (0);
		}
		init_philo(&state);
	}
	else
		write(1, "Wrong number of arguments\n", 26);
	return (0);
}
