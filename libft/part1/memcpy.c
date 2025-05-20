/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 22:14:29 by acasper           #+#    #+#             */
/*   Updated: 2025/05/18 21:35:48 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	*memcpy(void *dest, const void *scr, size_t n)
{
	unsigned char *d = (unsigned char*) dest;
	const unsigned char *s = (const unsigned char *) scr;

	while (n--)
		*d++ = *s++;
	return (dest);
}
