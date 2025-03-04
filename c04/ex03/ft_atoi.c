/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:55:53 by acasper           #+#    #+#             */
/*   Updated: 2025/03/04 20:15:46 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	ft_atoi(char *str)
{
	int	neg;
	int	num;
	int	temp;

	num = 0;
	neg = 0;
	while (*str)
	{
		if (str == '-')
			neg++;
		if (str >= 48 && <= 57)
		{
			temp = 0;
			temp = str + '0'
			num += temp;
		}
		if (str > 64)
		{
			
		}
		str++;
	}

	if (neg % 2 == 1)
		num *= -1;
	return (num);
}

#include <stdio.h>
int	main(void)
{
	int n;
	n = ft_atoi("42");
	printf("%d\n", n);
	n = ft_atoi("   ---+--+1234ab567");
	printf("%d\n", n);
	n = ft_atoi("fgfd");
	printf("%d\n", n);
	n = ft_atoi("");
	printf("%d\n", n);
}

