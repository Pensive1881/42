/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 22:13:49 by acasper           #+#    #+#             */
/*   Updated: 2025/05/19 00:09:32 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_bzero(void *str, size_t n)
{
	unsigned char *ptr = (unsigned char*) str;
	while (n > 0)
	{
		*ptr = 0;
		n--;
	}
	return (0);
}

/*
int     main()
{
        return (0);
}
*/
