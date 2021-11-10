/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snuts <snuts@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 15:36:35 by snuts             #+#    #+#             */
/*   Updated: 2021/10/09 15:36:35 by snuts            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_strlenx(char const *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		k;
	char	*str;

	i = 0;
	k = 0;
	if (!s1 || !s2)
		return (NULL);
	str = (char *) malloc (sizeof(char) * (ft_strlenx(s1)
				+ ft_strlenx(s2) + 1));
	if (str == NULL)
		return (NULL);
	while (s1[i] != '\0')
		str[k++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		str[k++] = s2[i++];
	str[k] = '\0';
	return (str);
}
