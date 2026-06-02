/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrajni <rrajni@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 12:38:18 by rrajni            #+#    #+#             */
/*   Updated: 2025/06/02 18:28:36 by rrajni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	if (!s || !f)
		return (NULL);
	str = (char *)malloc(ft_strlen(s) + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
/*#include <stdio.h>
char	sample_function(unsigned int i, char c)
{
	if (i % 2 == 0 && c >= 'a' && c <= 'z')
		return c - 32; // to uppercase
	else if (i % 2 == 0 && c >= 'A' && c <= 'Z')
		return c + 32; // to lowercase
	return c;
}

int	main(void)
{
	const char *original = "Hello, World!";
	char *result = ft_strmapi(original, sample_function);

	if (result)
	{
		printf("Original: %s\n", original);
		printf("Mapped  : %s\n", result);
		free(result); // don't forget to free the allocated string
	}
	else
	{
		printf("ft_strmapi returned NULL\n");
	}

	return 0;
}*/
