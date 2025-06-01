/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 23:42:26 by acasper           #+#    #+#             */
/*   Updated: 2025/05/25 20:53:38 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	counter(const char *s)
{
	int	i;

	i = 0;
	while (*s)
	{
		i++;
		s++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		len;
	int		i;
	int		j;

	len = counter(s1) + counter(s2);
	str = (char *)malloc((len + 1) * sizeof(char));
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}
/*
#include <stdio.h>
int     main(void)
{
	printf("miau & meow: %s", ft_strjoin("miau", "meow"));
        return (0);
}
*/
