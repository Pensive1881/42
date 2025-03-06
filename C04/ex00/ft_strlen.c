/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:51:27 by acasper           #+#    #+#             */
/*   Updated: 2025/03/03 19:26:07 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		str++;
		i++;
	}
	return (i);
}
/*
#include <stdio.h>
int	main(void)
{
	char	string[] = "meow";
	int num = ft_strlen(string);

	printf("%s\n", string);
	printf("%d", num);
	return (0);
}
*/
