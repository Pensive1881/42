/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 22:13:03 by acasper           #+#    #+#             */
/*   Updated: 2025/05/15 18:54:02 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	*memset(void *str, int c, size_t n)
{
	unsigned char *s;
	unsigned char value;

	*s = (unsigned char*)str;
	value = (unsigned char)value;
	while (n > 0)
	{
		*s++ = value;
		n--;
	}
	return (str);
}
