/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 22:51:44 by acasper           #+#    #+#             */
/*   Updated: 2025/03/11 23:03:33 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	ft_sqrt(int nb)
{
	int	left;
	int	right;
	int	middle;

	if (nb == 0 || nb == 1)
		return (nb);
	left = 1;
	right = nb;
	while (left <= right)
	{
		middle = (left + right) / 2;
		if (middle * middle == nb)
			return (middle);
		else if (middle * middle < nb)
			left = middle + 1;
		else if (middle * middle > nb)
			right = middle - 1;
	}
	return (0);
}

#include <stdio.h>
int	main(void)
{
	printf("Square Root of 0: %d\n", ft_sqrt(0));
	printf("Square Root of 1: %d\n", ft_sqrt(1));
	printf("Square Root of 2: %d\n", ft_sqrt(2));
	printf("Square Root of 3: %d\n", ft_sqrt(3));
	printf("Square Root of 4: %d\n", ft_sqrt(4));
	printf("Square Root of 5: %d\n", ft_sqrt(5));
	printf("Square Root of 6: %d\n", ft_sqrt(6));
	printf("Square Root of 7: %d\n", ft_sqrt(7));
	printf("Square Root of 8: %d\n", ft_sqrt(8));
	printf("Square Root of 9: %d\n", ft_sqrt(9));
	printf("Square Root of 81: %d\n", ft_sqrt(81));
	printf("Square Root of 82: %d\n", ft_sqrt(82));
	printf("Square Root of 99: %d\n", ft_sqrt(99));
	printf("Square Root of 100: %d\n", ft_sqrt(100));
	printf("Square Root of 101: %d\n", ft_sqrt(101));
	printf("Square Root of 144: %d\n", ft_sqrt(144));

	return (0);
}

