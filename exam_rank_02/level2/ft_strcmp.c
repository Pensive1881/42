/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 14:22:06 by acasper           #+#    #+#             */
/*   Updated: 2025/08/28 14:22:50 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	n;

	i = 0;
	while ((s1[i] || s2[i]) && (s1[i] == s2[i]))
		i++;

	return (s1[i] - s2[i]);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	printf("meow & meow : %d\n", ft_strcmp("meow", "meow"));
	printf("miau & meow : %d\n", ft_strcmp("miau", "meow"));
	printf("meowmiau & meow : %d\n", ft_strcmp("meowmiau", "meow"));

	return (0);
}
*/
