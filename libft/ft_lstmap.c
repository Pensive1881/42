/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 00:28:30 by acasper           #+#    #+#             */
/*   Updated: 2025/06/03 15:54:27 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *new_list;
	t_list *new_node;
	void *new_content;

	if (!lst || !f)
			return (NULL);
	new_list = NULL;
	while (lst)
	{
		new_content = f(lst->content);
		new_node = malloc(sizeof(t_list));
		if (!new_node)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		new_node->content = new_content;
		new_node->next = NULL;
		if (!new_list)
			new_list = new_node;
		else
		{
			t_list *temp = new_list;
			while (temp->next)
				temp = temp->next;
			temp->next = new_node;
		}
		lst = lst->next;
	}
	return (new_list);
}

/*
int	main(void)
{
		return (0);
}
*/
