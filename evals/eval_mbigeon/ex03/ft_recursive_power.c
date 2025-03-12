/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 22:48:02 by acasper           #+#    #+#             */
/*   Updated: 2025/03/11 19:37:38 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	else
		return (nb * ft_recursive_power(nb, power - 1));
}

#include <stdio.h>
int     main(void)
{
	printf("2^2: %d\n", ft_recursive_power(2, 2));
	printf("2^1: %d\n", ft_recursive_power(2, 1));
	printf("2^0: %d\n", ft_recursive_power(2, 0));
	printf("2^-1: %d\n", ft_recursive_power(2, -1));
	printf("0^0: %d\n", ft_recursive_power(0, 0));
	printf("4^4: %d\n", ft_recursive_power(4, 4));

	return (0);
}

