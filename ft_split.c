/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snuts <snuts@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 21:28:04 by snuts             #+#    #+#             */
/*   Updated: 2021/10/18 22:11:14 by snuts            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_count(char const *s, char c)
{
	char	*str;
	int		count;
	int		i;

	count = 0;
	i = 0;
	str = (char *) s;
	while (str[i] != '\0')
	{
		if (str[i] != c && (str[i + 1] == c || str[i + 1] == '\0'))
			count ++;
		i++;
	}
	return (count);
}

static int	ft_len(char *strr, char c)
{
	int	i;

	i = 0;
	while (strr[i] != c && strr[i] != '\0')
		i++;
	return (i);
}

static char	**add_words_to_str(char const *s, char c,
				int count_word, char **str);

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		count_word;

	if (s == NULL)
		return (NULL);
	count_word = 0;
	count_word = ft_count(s, c);
	str = (char **)malloc(sizeof(char *) * (count_word + 1));
	if (str == NULL)
		return (NULL);
	str[count_word] = NULL;
	str = add_words_to_str(s, c, count_word, str);
	return (str);
}

static char	**ft_free(char **v, int h)
{
	while (h > 0)
	{
		h--;
		free(v[h]);
	}
	free (v);
	return (NULL);
}

static char	**add_words_to_str(char const *s, char c,
				int count_word, char **str)
{
	int		i;
	int		k;
	int		x;
	int		j;

	k = 0;
	i = 0;
	while (i < count_word)
	{
		while (s[k] == c && s[k] != '\0')
			k++;
		x = 0;
		x = ft_len((char *)s + k, c);
		str[i] = (char *) malloc(sizeof(char) * (x + 1));
		if (str[i] == NULL)
			return (ft_free(str, i));
		str[i][x] = '\0';
		j = 0;
		while (s[k] != '\0' && s[k] != c)
			str[i][j++] = s[k++];
		i++;
	}
	return (str);
}
