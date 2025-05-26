/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 00:21:50 by acasper           #+#    #+#             */
/*   Updated: 2025/05/26 23:52:26 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
//#include "libft.h"

typedef struct s_list
{
	void		*content;
	struct s_list	*next;
} t_list;

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		i++;
		lst = lst->next;
	{
	return (i);
}
/*
#include <stdio.h>
int     main(void)
{
	printf("???", ft_lstsize(???);
        return (0);
}
*/
