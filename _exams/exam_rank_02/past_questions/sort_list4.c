/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 19:17:46 by acasper           #+#    #+#             */
/*   Updated: 2026/02/05 19:23:27 by acasper          ###   ########.fr       */
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
