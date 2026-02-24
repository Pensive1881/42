/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 15:57:25 by acasper           #+#    #+#             */
/*   Updated: 2026/01/21 16:23:01 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_atoi(const char *str)
{
	int	num;
	int	i;

	num = 0;
	i = 0;
	while (str[i])
	{
		num *= 10;
		num += str[i] - '0';
		i++;
	}
	return (num);
}

int	main(int argc, char **argv)
{
	int	i;
	
	if (argc != 2)
		return (0);
	printf(": %d\n", ft_atoi(argv[1]));

	return (0);
}
