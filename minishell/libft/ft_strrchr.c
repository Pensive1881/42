/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrajni <rrajni@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 12:52:36 by rrajni            #+#    #+#             */
/*   Updated: 2025/06/03 14:47:11 by rrajni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	const char	*last_occurrance;
	int			i;

	last_occurrance = NULL;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			last_occurrance = str + i;
		i++;
	}
	if ((char)c == '\0')
	{
		return ((char *)(str + i));
	}
	return ((char *)last_occurrance);
}
/*
#include <stdio.h>
int	main(void)
{
	char *a = "Hello Hell Hi";
	char ch = 'H';
	//const char	*result = ft_strrchr(a, ch);

	printf("%s\n", ft_strrchr(a, ch));
	return (0);
}*/
