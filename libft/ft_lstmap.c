/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 00:28:30 by acasper           #+#    #+#             */
/*   Updated: 2025/06/04 15:32:19 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static t_list	*create_node(void *content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*node;
	t_list	*tail;

	new = NULL;
	tail = NULL;
	if (!lst || !f)
		return (NULL);
	while (lst)
	{
		node = create_node(f(lst->content));
		if (!node)
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		if (!tail)
			new = node;
		else
			tail->next = node;
		tail = node;
		lst = lst->next;
	}
	return (new);
}

/*
int	main(void)
{
		return (0);
}
*/
