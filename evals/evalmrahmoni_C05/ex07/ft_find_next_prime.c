/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 22:55:02 by acasper           #+#    #+#             */
/*   Updated: 2025/03/11 23:08:14 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	ft_find_next_prime(int nb)
{
	int	i;

	if (nb < 2)
		return (2);
	i = 2;
	while (i < nb)
	{
		if (nb % i == 0)
			return (ft_find_next_prime(nb + 1));
		i++;
	}
	return (nb);
}

#include <stdio.h>
int	main(void)
{
	printf("-1? %d\n", ft_find_next_prime(-1));
	printf("0? %d\n", ft_find_next_prime(0));
	printf("1? %d\n", ft_find_next_prime(1));
	printf("2? %d\n", ft_find_next_prime(2));
	printf("3? %d\n", ft_find_next_prime(3));
	printf("4? %d\n", ft_find_next_prime(4));
	printf("6? %d\n", ft_find_next_prime(6));
	printf("10? %d\n", ft_find_next_prime(10));
	printf("90? %d\n", ft_find_next_prime(90));

	return (0);
}

