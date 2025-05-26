/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 00:24:55 by acasper           #+#    #+#             */
/*   Updated: 2025/05/27 00:18:22 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
//#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_list
{
	void		*content;
	struct s_list	*next;
} t_list



void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return;
	del(lst->content);
	free(lst);
	return (NULL);
}

/*
int     main(void)
{
        return (0);
}
*/
