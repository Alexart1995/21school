/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snuts <snuts@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 20:32:24 by snuts             #+#    #+#             */
/*   Updated: 2021/10/18 21:05:49 by snuts            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strchr(const char *s, int c)
{
	unsigned int		i;
	unsigned char		*str;

	i = 0;
	str = (unsigned char *) s;
	while (str[i] != '\0')
	{
		if (str[i] == (unsigned char) c)
			return ((char *)str + i);
		i++;
	}
	if (str[i] == '\0' && c == '\0')
		return ((char *)str + i);
	else
		return (NULL);
}
