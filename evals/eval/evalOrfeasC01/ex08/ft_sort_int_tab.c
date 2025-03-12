/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 21:10:01 by acasper           #+#    #+#             */
/*   Updated: 2025/02/25 20:57:45 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	temp;
	int	swap;
	int	i;
	int	j;

	i = 0;
	while (i <= size - 1)
	{
		swap = 0;
		j = 0;
		while (j <= size - 1)
		{
			if (tab[j] > tab[j + 1])
			{
				temp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = temp;
				swap = 1;
			}
			j++;
		}
		i++;
		if (swap == 0)
			return ;
	}
}

#include <stdio.h>

int	main(void)
{
	int	arr[] = {2, 5, 0, 1, 9, 4, 8, 6, 3, 7};
	int	size;
	int	*ptr;
	int	i;

	size = 10;
	ptr = arr;

	i = 0;
	while (i < size)
	{
		printf("%d ", arr[i]);
		i++;
	}
	printf("\n");
	ft_sort_int_tab(arr, size);
	i = 0;
	while (i < size)
	{
		printf("%d ", arr[i]);
		i++;
	}
}
