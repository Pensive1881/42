/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 23:40:30 by acasper           #+#    #+#             */
/*   Updated: 2025/05/26 22:29:16 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
//#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	int	i;

	str = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	while (i <= len)
	{
		str[i] = s[start];
		start++;
		i++;
	}
	str[i] = '\0';
	return (str);
}
/*
#include <stdio.h>
int     main(void)
{
	printf("miau meow, 5, 4: %s\n", ft_substr("miau meow", 5, 4));
        return (0);
}
*/
