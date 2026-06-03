/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrajni <rrajni@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 15:59:07 by rrajni            #+#    #+#             */
/*   Updated: 2025/05/19 17:32:06 by rrajni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *ptr, int c, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *)ptr;
	while (n != 0)
	{
		*p = (unsigned char) c;
		p++;
		n--;
	}
	return (ptr);
}

/* #include <stdio.h>

int	main(void)
{
	unsigned	char arr[10];
	size_t	i;

	ft_memset(arr, 'x', 10);
	i = 0;
	while (i < 10)
	{
		printf("%c", arr[i]);
		i++;
	}
	printf("\n");
	return (0);
}*/