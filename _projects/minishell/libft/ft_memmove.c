/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrajni <rrajni@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 20:59:02 by rrajni            #+#    #+#             */
/*   Updated: 2025/06/03 12:04:01 by rrajni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*dest_new;
	const unsigned char	*src_new;

	dest_new = (unsigned char *)dest;
	src_new = (const unsigned char *)src;
	if (dest_new == src_new || n == 0)
		return (dest_new);
	if (dest_new < src_new)
	{
		while (n--)
		{
			*dest_new++ = *src_new++;
		}
	}
	else
	{
		dest_new = dest_new + n;
		src_new = src_new + n;
		while (n--)
		{
			*--dest_new = *--src_new;
		}
	}
	return (dest);
}
// int	main(void)
// {
// 	char	data[] = "abcdef";

// 	ft_memmove(data + 2, data, 3);
// 	printf("%s\n", data);
// 	return (0);
// }
