/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptycho <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 15:28:00 by ptycho            #+#    #+#             */
/*   Updated: 2021/04/02 15:28:00 by ptycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H
# include <pthread.h>

typedef struct		s_state
{
	int				num_philo;
	int				time_die;
	int 			time_eat;
	int				time_sleep;
	int	 			must_eat;
	int 			is_died;
	pthread_mutex_t *fokes;
	pthread_mutex_t death;
	pthread_mutex_t out;
	pthread_mutex_t stat;
}					t_state;

typedef struct		s_philo
{
	int 			id;
	int 			must_eat;
	long 			meal_last;
	long 			meal_start;
	t_state			*state;
}					t_philo;

long 				get_current_time(void);
char				*ft_itoa(long n);
size_t				ft_strlen(const char *str);

#endif
