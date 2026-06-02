/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrajni <rrajni@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 14:50:28 by rrajni            #+#    #+#             */
/*   Updated: 2025/06/04 11:44:26 by rrajni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			return ((char *)(str + i));
		i++;
	}
	if ((char)c == '\0')
	{
		return ((char *)(str + i));
	}
	return (NULL);
}
/*
#include <stdio.h>

int	main(void)
{
	const char	*a = "hello world";
	char	ch = 'w';
	const char	*result = ft_strchr(a, ch);

	printf("%s\n", result);
	return (0);
}*/
