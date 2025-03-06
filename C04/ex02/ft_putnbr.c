/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:54:38 by acasper           #+#    #+#             */
/*   Updated: 2025/03/06 21:29:14 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
//write(1, &array[i], 1);

void	ft_putnbr(int nb)
{
	int		i;
	char	array[42];

	if (nb == -2147483648)
	{
		write (1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		write (1, "-", 1);
		nb *= -1;
	}
	i = 0;
	while (nb > 0)
	{
		array[i] = (nb % 10) + '0';
		nb /= 10;
		i++;
	}
	array[i] = '\0';
	while (i >= 0)
	{
		write (1, &array[i], 1);
		i--;
	}
}

int	main(void)
{
	int	num;

	num = 424242;
	ft_putnbr(num);
	write (1, "\n", 1);

	num = 0;
	ft_putnbr(num);
	write (1, "\n", 1);

	num = -2147483648;
	ft_putnbr(num);
	write (1, "\n", 1);

	num = 2147483647;
	ft_putnbr(num);
	write (1, "\n", 1);
}

