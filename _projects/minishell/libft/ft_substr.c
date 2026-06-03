/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrajni <rrajni@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 15:22:54 by rrajni            #+#    #+#             */
/*   Updated: 2025/06/04 11:48:07 by rrajni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	dest = (char *)malloc(len + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (i < len && s[start + i] != '\0')
	{
		dest[i] = s[start + i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/**/
/*int	main(void)*/
/*{*/
/*	char	const *str = "How is the weather today?";*/
/*	char	*result = ft_substr(str, 12, 24);*/
/**/
/*	printf("%s\n", result);*/
/*	return (0);*/
/*}*/
