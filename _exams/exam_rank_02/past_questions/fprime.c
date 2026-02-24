/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 13:50:20 by acasper           #+#    #+#             */
/*   Updated: 2026/02/04 18:23:12 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	int	i;
	int	num;

	i = 2;
	if (argc == 2)
	{
		num = atoi(argv[1]);
		if (num == 1)
			printf("1");
		while (i <= num)
		{
			if (num % i == 0)
			{
				printf("%d", i);
				if (num != i)
					printf("*");
				num /= i;
			}
			else
				i++;
		}
	}

	printf("\n");
	return (0);
}




#include <studio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	i = 2;
	while (i <= n)
	{
		if (n % i == 0)
		{
			printf("%d", i);
			if (n != i)
				printf("*");
			num /= i;
		}
		else
			i++;
	
	}

	printf("\n");
	return (0);
}
