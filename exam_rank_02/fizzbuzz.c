/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 16:22:38 by acasper           #+#    #+#             */
/*   Updated: 2025/08/19 16:41:01 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	putnbr(int n)
{
	char c;

	if (n >= 10)
		putnbr(n / 10);
	c = n % 10 + '0';
	write (1, &c, 1);
}

int	main(void)
{
	int	i;

	i = 1;
	while (i <= 100)
	{
		if (i % 3 == 0)
			write(1, "fizz", 4);
		if (i % 5 == 0)
			write (1, "buzz", 4);
		if (i % 3 != 0 && i % 5 != 0)
			putnbr(i);
		write (1, "\n", 1);
		i++;
	}
	return (0);
}

