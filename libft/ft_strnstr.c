/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 22:20:08 by acasper           #+#    #+#             */
/*   Updated: 2025/05/19 00:20:24 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int	i;
	int	j;

	if (!*needle)
		return ((char*) haystack);

	i = 0;
	while (haystack[i] && i < len)
	{
		j = 0;
		while(needle[j] && i + j < len && haystack[i + j] == needle[j])
			j++;
		if (!needle[j])
			return ((char*) haystack + i);
		i++;
	}
	return (NULL);
}

/*
int     main()
{
        return (0);
}
*/
