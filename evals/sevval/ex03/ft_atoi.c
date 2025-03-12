/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:55:53 by acasper           #+#    #+#             */
/*   Updated: 2025/03/10 18:12:40 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_atoi(char *str)
{
	int	num;
	int	neg;
	int	i;

	num = 0;
	neg = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg++;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		num *= 10;
		num += str[i] - '0';
		i++;
	}
	if (neg % 2 == 1)
		num *= -1;
	return (num);
}

#include <unistd.h>
#include <stdio.h>
int	main(void)
{
	int	n;

	n = ft_atoi("42");
	printf("%d\n", n);
	n = ft_atoi("   ---+--+1234ab567");
	printf("%d\n", n);
	n = ft_atoi("fgfd");
	printf("%d\n", n);
	n = ft_atoi("");
	printf("%d\n", n);

	return (0);
}

