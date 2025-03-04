/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:54:38 by acasper           #+#    #+#             */
/*   Updated: 2025/03/03 23:16:59 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putnbr(int nb)
{
	int	i;
	char	array[42];

	i = 0;
	while (nb > 0)
	{
		array[i] = (nb % 10) + '0';
		nb /= 10;
//		write(1, &array[i], 1);
		i++;
	}
	while (i >= 0)
	{
		write(1, &array[i], 1);
		i--;
	}
}

int	main(void)
{
	int num = 424242;

	ft_putnbr(num);
}

