/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrajni <rrajni@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 18:49:45 by rrajni            #+#    #+#             */
/*   Updated: 2025/06/04 11:42:26 by rrajni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *str, size_t n)
{
	unsigned char	*dest_new;
	unsigned char	*str_new;

	str_new = (unsigned char *)str;
	dest_new = (unsigned char *)dest;
	if (dest == str || n == 0)
		return (dest);
	while (n > 0)
	{
		*dest_new = *str_new;
		dest_new++;
		str_new++;
		n--;
	}
	return (dest);
}

//#include <stdio.h>
// int	main(void)
// {
// 	char	s[] = "No not yet!";
// 	char	d[50];

// 	ft_memcpy(d, s, 13);
// 	printf("%s\n", d);
// 	return (0);
// }
