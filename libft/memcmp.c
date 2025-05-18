/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 22:19:39 by acasper           #+#    #+#             */
/*   Updated: 2025/05/18 21:49:38 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	memcmp(const void *str1, const void *str2, size_t n)
{
	const unsigned char *ptr1 = str1;
	const unsigned char *ptr2 = str2;

	while (n--)
	{
		if (*ptr1 != *ptr2)
			return (ptr1 - ptr2);
		ptr1++;
		ptr2++;
	}
	return (0);
}
