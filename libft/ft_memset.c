/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 22:13:03 by acasper           #+#    #+#             */
/*   Updated: 2025/05/22 18:55:51 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *s;
	unsigned char value;

	*s = (unsigned char*) b;
	value = (unsigned char) value;
	while (len > 0)
	{
		*s++ = value;
		len--;
	}
	return (b);
}

/*
int     main()
{
        return (0);
}
*/
