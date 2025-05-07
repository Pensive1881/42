/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:54:38 by acasper           #+#    #+#             */
/*   Updated: 2025/03/10 17:25:03 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putnbr(int nb)
{
	char	str;

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
	if (nb < 10)
	{
		str = nb + '0';
		write (1, &str, 1);
		return ;
	}
	ft_putnbr(nb / 10);
	str = (nb % 10) + '0';
	write (1, &str, 1);
}
/*
int	main(void)
{
	ft_putnbr(424242);
	write (1, "\n", 1);

	ft_putnbr(0);
	write (1, "\n", 1);

	ft_putnbr(-2147483648);
	write (1, "\n", 1);

	ft_putnbr(2147483647);
	write (1, "\n", 1);
}
*/
