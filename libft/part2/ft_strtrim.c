/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 23:43:57 by acasper           #+#    #+#             */
/*   Updated: 2025/05/26 22:54:02 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
//#include "libft.h"
#include <unistd.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int	i;
	int	j;
	
	str = (char *)malloc(sizeof(char) * ());
	i = 0;
	j = 0;
	while (set[i])
	{
		while (s1[j] != set[i])
		{
			str[j] = s1[j]
			j++;
		}
		i++;
	}
	str[i] = '\0';
	return (str);
}

#include <stdio.h>

int     main(void)
{
	printf("%p\n", ft_strtrim("  miau meow  ", ' '));
        return (0);
}

