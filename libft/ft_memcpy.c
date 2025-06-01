/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 22:14:29 by acasper           #+#    #+#             */
/*   Updated: 2025/06/01 21:51:20 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *d = (unsigned char*) dst;
	const unsigned char *s = (const unsigned char *) src;

	while (n--)
		*d++ = *s++;
	return (dst);
}

/*
int     main()
{
        return (0);
}
*/
