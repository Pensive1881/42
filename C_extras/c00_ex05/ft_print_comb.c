/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 23:19:35 by acasper           #+#    #+#             */
/*   Updated: 2025/02/20 21:09:06 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_print_comb(void)
{
	int	x;
	int	y;
	int	z;

	x = 0;
	while (x <= '7')
	{
		y = x + 1;
		while (y <= '8')
		{
			z = y + 1;
			while (z <= '9')
			{
				write(1, &x, 1);
				write(1, &y, 1);
				write(1, &z, 1);
				if (x != '7' || y != '8' || z != '9')
					write(1, ", ", 2);
			}
			z++;
		}
		y++;
	}
	x++;

}

int	main(void)
{
	ft_print_comb();
}
