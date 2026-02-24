/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 19:10:41 by acasper           #+#    #+#             */
/*   Updated: 2026/02/05 19:15:51 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "list.h"

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	int	swap;
	t_list	*curr = lst;

	while (lst->next)
	{
		if (((*cmp)(lst->data, lst->data->next)) == 0)
		{
			swap = lst->data;
			lst->data = lst->data->next;
			lst->data->next = swap;
			lst = curr;
		}
		else
			lst = lst->next;
	}

	lst = curr;
	return (lst);
}

