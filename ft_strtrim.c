/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snuts <snuts@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 19:04:07 by snuts             #+#    #+#             */
/*   Updated: 2021/10/18 21:06:40 by snuts            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static	int	ft_comp(char *x, int c)
{
	int	i;

	i = 0;
	while (x[i] != '\0')
	{
		if (x[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static char	*ft_strim(char *s2, int start, int end)
{
	char	*str;
	int		j;
	int		k;

	str = malloc (sizeof(char) * ((end - start) + 1));
	if (str == NULL)
		return (NULL);
	j = 0;
	k = 0;
	k = start;
	while (j < (end - start))
	{
		str[j] = s2[k];
		j++;
		k++;
	}
	str[j] = '\0';
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*str;
	char	*s2;

	if (!s1 || !set)
		return (NULL);
	s2 = (char *)s1;
	start = 0;
	end = 0;
	while ((ft_comp((char *)set, s2[start]) == 1) && s2[start] != '\0')
		start++;
	end = ft_strlen(s2);
	while (start <= end && ft_comp((char *)set, s2[end - 1]) == 1)
		end--;
	str = ft_strim(s2, start, end);
	return (str);
}
