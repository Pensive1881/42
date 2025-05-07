/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 22:50:25 by acasper           #+#    #+#             */
/*   Updated: 2025/03/11 18:23:58 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	if (index == 0)
		return (0);
	if (index == 1)
		return (1);
	else
		return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
}
/*
#include <stdio.h>
int	main(void)
{
	printf("Index -1: %d\n", ft_fibonacci(-1));
	printf("Index 0: %d\n", ft_fibonacci(0));
	printf("Index 1: %d\n", ft_fibonacci(1));
	printf("Index 2: %d\n", ft_fibonacci(2));
	printf("Index 3: %d\n", ft_fibonacci(3));
	printf("Index 4: %d\n", ft_fibonacci(4));
	printf("Index 5: %d\n", ft_fibonacci(5));
	printf("Index 6: %d\n", ft_fibonacci(6));
	printf("Index 7: %d\n", ft_fibonacci(7));
	printf("Index 8: %d\n", ft_fibonacci(8));
	printf("Index 9: %d\n", ft_fibonacci(9));
	printf("Index 10: %d\n", ft_fibonacci(10));
}
*/
