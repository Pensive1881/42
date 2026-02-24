/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_power_of_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 14:25:39 by acasper           #+#    #+#             */
/*   Updated: 2025/08/28 14:26:05 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	is_power_of_2(unsigned int n)
{
	unsigned int p;

	p = 1;
	if (n == 0)
		return (0);
	while (p < n)
		p *= 2;

	return (p == n);
}

/*
#include <stdio.h>

int	main(void)
{
	printf("16: %d\n", is_power_of_2(16));
	printf("4: %d\n", is_power_of_2(4));
	printf("0: %d\n", is_power_of_2(0));
	printf("1: %d\n", is_power_of_2(1));
	printf("42: %d\n", is_power_of_2(42));

	return (0);
}
*/
