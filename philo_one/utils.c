/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptycho <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 14:43:00 by ptycho            #+#    #+#             */
/*   Updated: 2021/04/06 14:43:00 by ptycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>

long 	get_current_time(void)
{
	struct timeval timeval;
	gettimeofday(&timeval, NULL);
	return (timeval.tv_sec * 1000 + timeval.tv_usec * 0.001);
}

