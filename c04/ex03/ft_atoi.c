/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:55:53 by acasper           #+#    #+#             */
/*   Updated: 2025/03/05 19:45:49 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	ft_atoi(char *str)
{
	int	neg;
	int	num;
	int	temp;
	int	i;

	i = 0;
	num = 0;
	neg = 0;
	while (*str[i])
	{
		if (str[i] == '+' || str[i] == '\v' || str[i] == '\f' || str[i] == ' ' || str[i] == '\t'|| str[i] == '\r')
			i++;
		if (str[i] == '-')
		{
			neg++;
			i++;
		}
		if (str[i] >= 48 && str[i] <= 57)
		{
			temp = 0;
			num += (str[i] - '0');
			i++;
		}
		i++;
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

