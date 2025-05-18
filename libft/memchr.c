/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 22:19:04 by acasper           #+#    #+#             */
/*   Updated: 2025/05/18 21:52:58 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	*memchr(const void *str, int c, size_t n)
{
	const unsigned char *ptr = str;

	while (n--)
	{
		if (*ptr == (unsigned char) c)
			return ((void *)ptr);
		ptr++;
	}
	return (NULL);
}
