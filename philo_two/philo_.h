/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_two.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptycho <marvin@42.fr>                     +#+  +:+       +#+         */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 17:30:00 by ptycho            #+#    #+#             */
/*   Updated: 2021/04/08 17:30:00 by ptycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_TWO_H
# define PHILO_TWO_H
# include <semaphore>

typedef struct		s_state
{
	int				num_philo;
	int				time_die;
	int 			time_eat;
	int				time_sleep;
	int	 			must_eat;
	long 			meal_start;
	int 			is_died;
	sem_t			*fokes;
	sem_t			*death;
	sem_t			*out;
	sem_t			*stat;
	sem_t			*wait;
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
