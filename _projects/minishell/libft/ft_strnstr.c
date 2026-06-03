/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrajni <rrajni@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:04:07 by rrajni            #+#    #+#             */
/*   Updated: 2025/05/19 15:38:11 by rrajni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*s2 == '\0')
		return ((char *)(s1));
	while (s1[i] != '\0' && i < n)
	{
		j = 0;
		while (s2[j] != '\0' && s1[i + j] && 
			(i + j) < n && s1[i + j] == s2[j])
		{
			j++;
		}
		if (s2[j] == '\0')
		{
			return ((char *)(s1 + i));
		}
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>
int	main(void)
{
	char	str[] = "I am looking for my camera.";
	char	str1[] = "camera";

	printf("%s\n", ft_strnstr(str, str1, 89));
	return (0);

}*/