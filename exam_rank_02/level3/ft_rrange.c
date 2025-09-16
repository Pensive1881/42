/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 21:41:57 by acasper           #+#    #+#             */
/*   Updated: 2025/09/16 22:12:06 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	*ft_rrange(int start, int end)
{
	int	len;
	int	*arr;
	int	i;

	if (end >= start)
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
			arr[i] = end - i;
		else
			arr[i] = end + i;
		i++;
	}
	return (arr);
}
/*
#include <stdio.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	int	*arr;
	int	start;
	int	end;
	int	len;
	int	i;

	if (argc != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	start = atoi(argv[1]);
	end = atoi(argv[2]);
	arr = ft_rrange(start, end);
	len = (end >= start) ? (end - start + 1) : (start - end + 1);
	if (!arr)
		return (1);
	printf("ft_range(%d, %d): ", start, end);
	i = 0;
	while (i < len)
	{
		printf("%d ", arr[i]);
		i++;
	}
	write(1, "\n", 1);
	free (arr);
	return (0);
}
*/
