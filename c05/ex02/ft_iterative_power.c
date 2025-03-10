/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 22:46:42 by acasper           #+#    #+#             */
/*   Updated: 2025/03/10 22:29:15 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	ft_iterative_power(int nb, int power)
{
	int	sum;
	int 	i;

	if (power < 0)
		return (0);
	if (power == 0 && nb == 0)
		return (1);
	i = 0;
	sum = 1;
	while (i < power)
	{
		sum *= nb;
		i++;
	}
	return (0);
}

#include <stdio.h>
int	main(void)
{
	printf("%d\n", ft_iterative_power(2, 2));
	return (0);
}
