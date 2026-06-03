/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrajni <rrajni@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 12:52:57 by rrajni            #+#    #+#             */
/*   Updated: 2025/06/03 12:46:55 by rrajni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = 0;
	while (src[src_len] != '\0')
	{
		src_len++;
	}
	if (size == 0)
		return (src_len);
	while (i < size - 1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (src_len);
}
// #include <stdio.h>

// int	main(void)
// {
// 	char	S1[] = "Hello there!";
// 	char	S2[50];

// 	ft_strlcpy(S2, S1, 5);
// 	printf("%s\n" "%s\n", S1, S2);
// 	printf("%u\n", ft_strlcpy(S2, S1, 5));
// 	return (0);
// }
