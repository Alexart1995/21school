/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snuts <snuts@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 21:08:44 by snuts             #+#    #+#             */
/*   Updated: 2021/10/18 21:06:36 by snuts            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;
	unsigned int	k;
	unsigned int	count;

	count = 0;
	i = 0;
	k = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char) c)
		{
			k = i;
			count++;
		}
		i++;
	}
	if (s[i] == '\0' && c == '\0')
		return ((char *)s + i);
	else if (k == 0 && count == 0)
		return (NULL);
	else
		return ((char *)s + k);
}
