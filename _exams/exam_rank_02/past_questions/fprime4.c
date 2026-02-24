/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 19:30:34 by acasper           #+#    #+#             */
/*   Updated: 2026/02/05 19:38:08 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	int	i;
	int	n;

	if (argc == 2)
	{
		n = atoi(argv[1]);
		if (n == 1)
			printf("1");
		i = 2;
		while (i <= n)
		{
			if (n % i == 0)
			{
				printf("%d", i);
				if (n != i)
					printf("*");
				n /= i;
			}
			else
				i++;
		}
	}

	printf("\n");
	return (0);
}

