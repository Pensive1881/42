/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 18:50:30 by acasper           #+#    #+#             */
/*   Updated: 2026/01/22 19:00:04 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include ""

int	ft_list_size(t_list *begin_list)
{
	int	i;

	i = 0;
	while(begin_list)
	{
		i++;
		begin_list = begin_list->next;
	}
	return (i);
}
