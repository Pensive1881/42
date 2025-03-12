/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 22:42:32 by acasper           #+#    #+#             */
/*   Updated: 2025/03/10 21:18:24 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	ft_iterative_factorial(int nb)
{
	int	fact;
	int	i;

	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	fact = 1;
	i = 1;
	while (i <= nb)
	{
		fact *= i;
		i++;
	}
	return (fact);
}
/*
#include <stdio.h>
int	main(void)
{
	int	n;

	n = 0;
	printf("%d! = %d", n, ft_iterative_factorial(n));
	n = 1;
	printf("\n%d! = %d", n, ft_iterative_factorial(n));
	n = 2;
	printf("\n%d! = %d", n, ft_iterative_factorial(n));
	n = 3;
	printf("\n%d! = %d", n, ft_iterative_factorial(n));
	n = 8;
	printf("\n%d! = %d", n, ft_iterative_factorial(n));
	n = -1;
	printf("\n%d! = %d", n, ft_iterative_factorial(n));
}
*/