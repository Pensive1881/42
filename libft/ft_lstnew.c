/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 23:56:31 by acasper           #+#    #+#             */
/*   Updated: 2025/05/26 23:55:13 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
//#include "libft.h"

typedef struct s_list
{
	void		*content;
	struct s_list	*next;
} t_list;

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

/*
int     main(void)
{
        return (0);
}
*/
