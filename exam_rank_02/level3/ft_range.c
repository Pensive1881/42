/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 18:56:23 by acasper           #+#    #+#             */
/*   Updated: 2025/09/12 18:10:54 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	*ft_range(int start, int end)
{
	int	len;
	int	*arr;
	int	i;

	if (start <= end)
		len = end - start + 1;
	else
		len = start - end + 1;
	arr = (int *)malloc(sizeof(int) * len);
	if (!arr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		if (start <= end)
			arr[i] = start + i;
		else
			arr[i] = start - i;
		i++;
	}
	return (arr);
}
/*
#include <unistd.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	int	*arr;
	if (argc != 3)
	{
		write (1, "\n", 1);
		return (0);
	}
	int start = atoi(argv[1]);
	int end = atoi(argv[2]);
	arr = ft_range(start, end);
	int	len = (end >= start) ? (end - start + 1) : (start - end + 1);

	if (!arr)
		return (1);
	int i = 0;
	printf("ft_range(%d, %d): ", start, end);
	i = 0;
	while (i < len)
	{
		printf("%d ", arr[i]);
		i++;
	}
	write (1, "\n", 1);
	if (argc != 3)
		write (1, "\n", 1);
	free(arr);
	return (0);
}
*/
