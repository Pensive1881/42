/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 18:48:19 by acasper           #+#    #+#             */
/*   Updated: 2025/05/19 00:09:55 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if(size && count > SIZE_MAX / size)
		return (NULL);
	*ptr = malloc(count * size);
	if (ptr)
		memset(ptr, 0, count * size);

	return (ptr);
}

/*
int     main()
{
        return (0);
}
*/
