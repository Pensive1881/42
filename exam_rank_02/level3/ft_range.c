/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 18:56:23 by acasper           #+#    #+#             */
/*   Updated: 2025/09/12 16:49:31 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	*ft_range(int start, int end);
{
	int	len;
	int	*arr;
	int	i;

	len = (end >= start) ? (end - start + 1) : (start - end + 1)
	arr = (int *)malloc(sizeof(int) * len);
	if (!arr)
		return (NULL);

	i = 0;
	while (i < len)
	{
		
		i++;
	}
	return (arr);
}

#include <stdio.h>

int	main(void)
{
	return (0);
}
