/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 23:45:27 by acasper           #+#    #+#             */
/*   Updated: 2025/05/27 21:56:15 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
//#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

int	counter(const char *s, char c)
{
	int	count;
	int	found;
	
	count = 0;
	found = 0;
	while (*s)
	{
		if (*s != c && found == 0)
		{
			found = 1;
			count++;
		}
		else if (*s == c)
			found = 0;
		s++;
	}

	return (count);
}

char	**ft_split(char const *s, char c)
{
	char 	**str;
	int	word_len;
	int	word_count;
	int	i;

	if (!s)
		return (NULL);
	word_count = counter(s, c);
	str = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (*s)
	{
		
		i++;
	}

	str[i] = '\0';
	return (str);
}

#include <stdio.h>

int     main(void)
{
	printf("meow miau meow, ' ': %p\n", *ft_split("meow miau meow", ' '));
        return (0);
}

