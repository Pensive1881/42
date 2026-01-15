/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 21:04:57 by acasper           #+#    #+#             */
/*   Updated: 2025/03/12 22:02:51 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <errno.h>

int	*ft_range(int min, int max)
{
	int	*array;
	int	i;

	if (min >= max)
		return (NULL);
	array = (int *)malloc(sizeof(int) * (max - min));
	if (!array)
		return (NULL);
	i = 0;
	while (i < max - min)
	{
		array[i] = min + i;
		i++;
	}
	return (array);
}
/*
#include <unistd.h>
#include <stdio.h>
int	main(void)
{
	int *arr = ft_range(42, 69);

	int i = 0;
	while (arr[i])
	{
		printf("%d ", arr[i]);
		i++;

	}
//	printf("%d", *arr);

	free(arr);
	return (0);
}
*/
