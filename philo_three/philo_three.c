/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptycho <marvin@42.fr>                     +#+  +:+       +#+         */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 17:30:00 by ptycho            #+#    #+#             */
/*   Updated: 2021/04/08 17:30:00 by ptycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

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

int 	init_semaphoras(t_state *state)
{
	sem_unlink("out");
	sem_unlink("wait");
	sem_unlink("forks");
	sem_unlink("death");
	sem_unlink("stat");
	sem_unlink("someone_is_died");
	state->out = sem_open("out", O_CREAT, 0660, 1);
	if (state->out < 0)
		return (0);
	state->someone_is_died = sem_open("someone_is_died", O_CREAT, 0660, 1);
	if (state->someone_is_died < 0)
		return (0);
	state->wait = sem_open("wait", O_CREAT, 0660, 1);
	if (state->wait < 0)
		return (0);
	state->forks = sem_open("forks", O_CREAT, 0660, state->num_philo);
	if (state->forks < 0)
		return (0);
	state->death = sem_open("death", O_CREAT, 0660, 1);
	if (state->death < 0)
		return (0);
	state->stat = sem_open("stat", O_CREAT, 0660, 1);
	if (state->stat < 0)
		return (0);
	return (1);
}

int		get_info_from_argum(int argc, char **argv, t_state *state)
{
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
	if (!init_semaphoras(state))
		return (0);
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
	sem_wait(philo->state->out);
	enjoy_write(mes, philo);
	sem_post(philo->state->out);
}

void 	*check_mortality(void* stat)
{
	t_philo *philo;

	philo = (t_philo *)stat;
	while (1)
	{
		sem_wait(philo->state->stat);
		if (get_current_time() - philo->meal_last > philo->state->time_die)
			break ;
		sem_post(philo->state->stat);
		usleep(10);
	}
	sem_post(philo->state->stat);
	if (philo->state->must_eat)
		return (NULL);
	print_stat(" is dead\n", philo);
	philo->state->is_died = 1;
	sem_post(philo->state->death);
	sem_post(philo->state->someone_is_died);
	return (NULL);
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
	sem_wait(philo->state->wait);
	sem_wait(philo->state->forks);
	print_stat(" has taken a fork\n", philo);
	sem_wait(philo->state->forks);
	print_stat(" has taken a fork\n", philo);
	sem_post(philo->state->wait);
	print_stat(" is eating\n", philo);
	sem_wait(philo->state->stat);
	philo->meal_last = get_current_time();
	sem_wait(philo->state->stat);
	enjoy_sleep(philo->state->time_eat);
	sem_post(philo->state->forks);
	sem_post(philo->state->forks);
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
	t_philo 		*philo;
	pid_t			process;
	int				*forks_for_philo;

	philo = malloc(sizeof(t_philo) * state->num_philo);
	forks_for_philo = malloc(sizeof(int) * state->num_philo);
	i = 0;
	state->is_died = 0;
	sem_wait(state->someone_is_died);
	while (i < state->num_philo)
	{
		process = fork();
		if (process == 0)
		{
			philo[i].id = i;
			philo[i].state = state;
			philo[i].must_eat = state->must_eat;
			start_simulation(&philo[i]);
			exit(0);
		}
		else
			forks_for_philo[i++] = process;
	}
	sem_post(state->someone_is_died);
	i = -1;
	while (++i < state->num_philo)
		kill(forks_for_philo[i], SIGSEGV);
	free(forks_for_philo);
	free(philo);
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
		sem_close(state.forks);
		sem_close(state.wait);
		sem_close(state.out);
		sem_close(state.stat);
		sem_close(state.death);
	}
	else
		write(1, "Wrong number of arguments\n", 26);
	return (0);
}
