/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 22:46:42 by acasper           #+#    #+#             */
/*   Updated: 2025/03/11 15:40:52 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	ft_iterative_power(int nb, int power)
{
	int	product;
	int	i;

	if (power < 0)
		return (0);
	if (power == 0 && nb == 0)
		return (1);
	i = 0;
	product = 1;
	while (i < power)
	{
		product *= nb;
		i++;
	}
	return (product);
}

#include <stdio.h>
int	main(void)
{
	printf("2^2: %d\n", ft_iterative_power(2, 2));
	printf("2^1: %d\n", ft_iterative_power(2, 1));
	printf("2^0: %d\n", ft_iterative_power(2, 0));
	printf("2^-1: %d\n", ft_iterative_power(2, -1));
	printf("0^0: %d\n", ft_iterative_power(0, 0));
	printf("4^4: %d\n", ft_iterative_power(4, 4));
	return (0);
}
