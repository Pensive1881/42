/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 18:56:23 by acasper           #+#    #+#             */
/*   Updated: 2025/09/12 17:52:24 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

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


int	main(int argc, char **argv)
{
	int	*arr = ft_range(argv[1], argv[2]);
	int	len = (argv[2] >= argv[1]) ? (argv[2] - argv[1] + 1) : (argv[1] - argv[2] + 1)
	int	i;

	if (argc != 3)
	{
		write (1, "\n", 1);
		return (0);
	}
	if (!arr)
		return (1);

	i = 0;
	printf("ft_range(%d, %d): ", argv[1], argv[2]);
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

