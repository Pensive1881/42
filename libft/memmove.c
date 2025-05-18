/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 22:15:00 by acasper           #+#    #+#             */
/*   Updated: 2025/05/18 21:26:52 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	*memmove(void *dest, const void *src, size_t n)
{
	unsigned char *d = (unsigned char*) dest;
	const unsigned char *s = (const unsigned char *) src;

	if (d = s || n = 0)
		return (dest);
	if (d < s || d >= s + n)
	{
		while (n--)
			*d++ = *s++;
	}
	else
	{
		d += n;
		s += n;
		while (n--)
			*(--d) = *(--s);
			
	}
	return (dest);
}
