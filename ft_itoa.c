/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snuts <snuts@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 18:03:44 by snuts             #+#    #+#             */
/*   Updated: 2021/10/18 21:04:40 by snuts            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

static int	ft_len_10(long long x)
{
	int	count;

	count = 1;
	while ((x / 10) != 0)
	{
		count++;
		x /= 10;
	}
	return (count);
}

static char	*f_ioa(int min, int count, int n, char *str)
{
	if (min == -1)
	{
		while (count >= 1)
		{
			str[count] = ((-1) * (long long)n % 10) + '0';
			count --;
			n /= 10;
		}
		str[count] = '-';
		return (str);
	}
	else if (min == 1)
	{
		while (count >= 0)
		{
			str[count] = ((long long)n % 10) + 48;
			count --;
			n /= 10;
		}
		return (str);
	}
	return (NULL);
}

char	*ft_itoa(int n)
{
	int			min;
	long long	x;
	int			count;
	char		*str;

	min = 1;
	x = (long long) n;
	count = ft_len_10 (x);
	if (n < 0)
	{
		count++;
		min = -1;
	}
	str = (char *) malloc (sizeof(char) * (count + 1));
	if (str == NULL)
		return (NULL);
	str[count] = '\0';
	count --;
	return (f_ioa(min, count, n, str));
}
