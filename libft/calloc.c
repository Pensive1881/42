/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 18:48:19 by acasper           #+#    #+#             */
/*   Updated: 2025/05/18 23:21:51 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdlib.h>

void	*calloc(size_t count, size_t size)
{
	void	*ptr;

	if(size && count > SIZE_MAX / size)
		return (NULL);
	*ptr = malloc(count * size);
	if (ptr)
		memset(ptr, 0, count * size);

	return (ptr);
}
