/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isalpha.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 20:27:10 by acasper           #+#    #+#             */
/*   Updated: 2025/05/12 22:10:30 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	isalpha(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 65)
			return (0);
		else if (str[i] > 90 && str[i] < 97)
			return (0);
		else if (str[i] > 122)
			return (0);
		i++;
	}
	return (1);
}
/*
#include <stdio.h>
int	main(void)
{
	printf("miau: %d\n", isalphaa("miau"));
	printf("mia0: %d\n", isalphaa("mia0"));
	printf("123: %d\n", isalphaa("123"));
	printf("m m: %d\n", isalphaa("m m"));
	return (0);
}
*/
