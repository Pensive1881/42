/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:34:22 by acasper           #+#    #+#             */
/*   Updated: 2025/03/10 14:23:54 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

char	*ft_strcat(char *dest, char *src)
{
	char	*pointer;

	pointer = dest;
	while (*pointer)
		pointer++;
	while (*src)
	{
		*pointer = *src;
		src++;
		pointer++;
	}
	*pointer = '\0';
	return (dest);
}
/*
#include <stdio.h>
int	main(void)
{
	char	string1[42] = "miau";
	char	string2[42] = "meow";

	printf("%s\n", ft_strcat(string1, string2));

	return (0);
}
*/
