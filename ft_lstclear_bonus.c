/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snuts <snuts@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 16:14:14 by snuts             #+#    #+#             */
/*   Updated: 2021/10/18 21:04:49 by snuts            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;
	t_list	*begin;

	begin = *lst;
	while (begin)
	{
		tmp = begin -> next;
		if (del)
		{
			del(begin -> content);
		}
		free(begin);
		begin = tmp;
	}
	*lst = NULL;
}
