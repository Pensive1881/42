/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bzero.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 22:13:49 by acasper           #+#    #+#             */
/*   Updated: 2025/05/15 18:43:18 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	bzero(void *str, size_t n)
{
	unsigned char *ptr = (unsigned char*) str;
	while (n > 0)
	{
		*ptr = 0;
		n--;
	}
	return (0);
}
