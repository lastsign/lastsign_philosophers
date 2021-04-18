/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_libft.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptycho <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:37:00 by ptycho            #+#    #+#             */
/*   Updated: 2021/04/07 14:37:00 by ptycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_from(char *str, int n, int len)
{
	int	m;

	m = n;
	if (n < 0)
	{
		str[0] = '-';
		m = -n;
	}
	while (len--)
	{
		str[len] = m % 10 + '0';
		m /= 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}

char	*ft_itoa_special(char *str, char *tra)
{
	int	n;

	str[11] = '\0';
	n = 10;
	while (tra[n])
	{
		str[n] = tra[n];
		n--;
	}
	return (str);
}

char	*ft_itoa(long n)
{
	int		m;
	int		len;
	char	*str;

	m = n;
	len = 0;
	if (n <= 0)
		len = 1;
	while (m != 0)
	{
		len++;
		m /= 10;
	}
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (n == -2147483648)
		str = ft_itoa_special(str, "-2147483648");
	else
	{
		str = ft_from(str, n, len);
		str[len] = '\0';
	}
	return (str);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
