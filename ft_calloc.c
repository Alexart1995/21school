/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snuts <snuts@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 19:23:21 by snuts             #+#    #+#             */
/*   Updated: 2021/10/18 21:04:15 by snuts            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)malloc(size * count);
	if (str == NULL)
		str = NULL;
	else
		ft_memset(str, 0, size * count);
	return ((void *)str);
}
