/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snuts <snuts@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 21:36:29 by snuts             #+#    #+#             */
/*   Updated: 2021/10/18 21:06:09 by snuts            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len1;

	i = 0;
	len1 = 0;
	while (dst[len1] != '\0' && len1 < dstsize)
		len1++;
	while ((len1 + i + 1 < dstsize) && (src[i] != '\0'))
	{
		dst[len1 + i] = src[i];
		i++;
	}
	if (len1 != dstsize)
		dst[len1 + i] = '\0';
	return (ft_strlen(src) + len1);
}
