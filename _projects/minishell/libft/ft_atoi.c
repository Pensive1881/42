/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrajni <rrajni@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 14:36:33 by rrajni            #+#    #+#             */
/*   Updated: 2025/06/02 18:23:46 by rrajni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
	{
		i++;
	}
	if (str[i] == '-')
	{
		sign = -sign;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		result = (result * 10 + (str[i] - '0'));
		i++;
	}
	return (result * sign);
}
/*
#include <stdio.h>

int	main(void)
{
	char	Str[] = "-45we12";
	char	ptr[] = " +-3er";
	char	qtr[] = "string";

	printf("%d\n", ft_atoi(Str));
	printf("%d\n", ft_atoi(ptr));
	printf("%d\n", ft_atoi(qtr));
	return (0);
}*/
