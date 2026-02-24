/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 14:26:45 by acasper           #+#    #+#             */
/*   Updated: 2025/08/28 14:27:15 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	max(int* tab, unsigned int len)
{
	int	i;
	int	bubble;

	bubble = tab[0];
	i = 0;
	if (len == 0)
		return (0);
	while(i < len)
	{
		if (tab[i] > bubble)
			bubble = tab[i];
		i++;
	}

	return (bubble);
}

/*
#include <stdio.h>

int	main(void)
{
	int arr1[] = {1, 2, 3, 4, 5};
	printf("1, 2, 3, 4, 5: %d\n", max(arr1, 5));
        int arr2[] = {9, 0, 1, 4, 5, 8, 8, 20};
        printf("9, 0, 1, 4, 5, 8, 8, 20: %d\n", max(arr2, 8));
        int arr3[] = {7};
        printf("7: %d\n", max(arr3, 1));
        int arr4[] = {2, 9, 3, 3, 8, 7, 7};
        printf("2, 9, 3, 3, 8, 7, 7: %d\n", max(arr4, 7));
        int arr5[] = {};
        printf(" : %d\n", max(arr5, 0));

	return (0);
}
*/
