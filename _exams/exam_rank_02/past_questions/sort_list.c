/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 16:03:24 by acasper           #+#    #+#             */
/*   Updated: 2026/01/30 19:14:04 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "list.h"

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	int	swap;
	t_list	*curr = lst;

	while (lst->next)
	{
		if (((*cmp)(lst->data, lst->next->data)) == 0)
		{
			swap = lst->data;
			lst->data = lst->next->data;
			lst->next->data = swap;
			lst = curr;
		}
		else
			lst = lst->next;
	}
	lst = curr;

	return (lst);
}

t_list()
{
	int	swap;
	t_list	*curr = lst;

	while (lst->next)
	{
		if (((*cmp)(lst->data, lst->next->data)) = 0)
		{
			swap = lst->data;
			lst->data = lst->next->data;
			lst->next->data = swap;
			lst = curr;
		}
		else
			lst = lst-next;
	}
	lst = curr;
	return ();
}
