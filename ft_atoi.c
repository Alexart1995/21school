/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snuts <snuts@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 19:54:08 by snuts             #+#    #+#             */
/*   Updated: 2021/10/16 22:01:55 by snuts            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	min_max(unsigned long long int num, int min, const char *str)
{
	int	i;

	i = 0;
	if (*str <= '0' && *str >= '9')
		str++;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (i > 19 || num > 9223372036854775807)
	{
		if (min == 1)
			return (-1);
		else if (min == -1)
			return (0);
	}
	return (min * num);
}

int	ft_atoi(const char *str)
{
	int						i;
	unsigned long long int	num;
	int						min;

	min = 1;
	num = 0;
	i = 0;
	while ((str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		&& str[i] != '\0')
		i++;
	if (str[i] == '-')
	{
		i++;
		min = -1;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] <= '9' && str[i] >= '0' && str[i] != '\0')
	{
		num = num * 10 + (str[i] - 48);
		i++;
	}
	return (min_max(num, min, str));
}
