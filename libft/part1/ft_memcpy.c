/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 22:14:29 by acasper           #+#    #+#             */
/*   Updated: 2025/05/19 00:13:07 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void restricted *dst, const void restricted *src, size_t n)
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
