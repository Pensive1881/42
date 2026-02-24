/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 18:23:28 by acasper           #+#    #+#             */
/*   Updated: 2026/02/04 18:29:08 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	int	i;
	int	n;

	i = 2;
	if (argc == 2)
	{
		n = atoi(argv[1]);
		if (n == 1)
			printf("1");
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

