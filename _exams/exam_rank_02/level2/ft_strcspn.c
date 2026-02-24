/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 14:24:15 by acasper           #+#    #+#             */
/*   Updated: 2025/08/28 14:24:57 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
size_t	ft_strcspn(const char *s, const char *reject)
{
	int	i;
	int	j;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (reject[j])
		{
			if (s[i] == reject[j])
				return (i);
			j++;
		}
		i++;
	}

	return (i);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	printf("hello, world, ,!: %zu\n", ft_strcspn("hello, world", ",!"));
	printf("abcdef, xyz: %zu\n", ft_strcspn("abcdef", "xyz"));
	printf("123-456, -: %zu\n", ft_strcspn("123-456", "-"));
	printf("hello, world, h: %zu\n", ft_strcspn("hello, world", "h"));

	return (0);
}
*/
