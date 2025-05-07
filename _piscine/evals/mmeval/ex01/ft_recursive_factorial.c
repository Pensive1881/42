/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 22:45:11 by acasper           #+#    #+#             */
/*   Updated: 2025/03/10 21:52:33 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	return (nb * ft_recursive_factorial(nb - 1));
}

#include <stdio.h>
int	main(void)
{
	int     n;

	n = 0;
	printf("%d! = %d", n, ft_recursive_factorial(n));
	n = 1;
	printf("\n%d! = %d", n, ft_recursive_factorial(n));
	n = 3;
	printf("\n%d! = %d", n, ft_recursive_factorial(n));
	n = 34;
	printf("\n%d! = %d", n, ft_recursive_factorial(n));
	n = 9;
	printf("\n%d! = %d", n, ft_recursive_factorial(n));
	n = 4;
	printf("\n%d! = %d", n, ft_recursive_factorial(n));

	return (0);
}
