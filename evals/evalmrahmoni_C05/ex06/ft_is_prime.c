/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 22:53:48 by acasper           #+#    #+#             */
/*   Updated: 2025/03/11 23:06:38 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	ft_is_prime(int nb)
{
	int	i;

	i = 2;
	if (nb < 2)
		return (0);
	while (i < nb)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

#include <stdio.h>
int	main(void)
{
	printf("Is -1 prime? %d\n", ft_is_prime(-1));
	printf("Is 0 prime? %d\n", ft_is_prime(0));
	printf("Is 1 prime? %d\n", ft_is_prime(1));
	printf("Is 2 prime? %d\n", ft_is_prime(2));
	printf("Is 3 prime? %d\n", ft_is_prime(3));
	printf("Is 4 prime? %d\n", ft_is_prime(4));
	printf("Is 5 prime? %d\n", ft_is_prime(5));
	printf("Is 6 prime? %d\n", ft_is_prime(6));
	printf("Is 7 prime? %d\n", ft_is_prime(7));
	printf("Is 8 prime? %d\n", ft_is_prime(8));
	printf("Is 9 prime? %d\n", ft_is_prime(9));
	printf("Is 10 prime? %d\n", ft_is_prime(10));
	printf("Is 11 prime? %d\n", ft_is_prime(11));
	printf("Is 12 prime? %d\n", ft_is_prime(12));

	return (0);
}

