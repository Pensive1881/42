/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrajni <rrajni@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 14:10:48 by rrajni            #+#    #+#             */
/*   Updated: 2025/06/02 15:41:40 by rrajni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*ptr;
	size_t			i;
	unsigned char	*p;

	if (nmemb == 0 || size == 0)
	{
		return ((void *)malloc(0));
	}
	if (size > SIZE_MAX / nmemb)
	{
		return (NULL);
	}
	ptr = (void *)malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	p = (unsigned char *)ptr;
	i = 0;
	while (i < nmemb * size)
	{
		p[i] = 0;
		i++;
	}
	return (ptr);
}
/*#include <stdio.h>
int	main(void)
{
	int	*p = ft_calloc(4, sizeof(int));
	printf("%d", p[0]);
	printf("%d", p[1]);
	printf("%d", p[2]);
	printf("%d", p[3]);
	free(p);
	return (0);
}*/
