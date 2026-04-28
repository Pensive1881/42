/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrajni <rrajni@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:07:59 by rrajni            #+#    #+#             */
/*   Updated: 2025/05/21 13:11:11 by rrajni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t	n)
{
	const unsigned char	*p;
	unsigned char		value;
	size_t				i;

	value = (unsigned char)c;
	p = (const void *)s;
	i = 0;
	while (i < n)
	{
		if (p[i] == value)
		{
			return ((void *)(s + i));
		}
		i++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	char	test[] = "Lets watch a movie.";
// 	char	value = 'p';clea
// 	char	*result = (char *)ft_memchr(test, value, 12);
// 	printf("%s\n", result);
// 	return (0);
// }
