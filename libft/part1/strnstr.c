/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 22:20:08 by acasper           #+#    #+#             */
/*   Updated: 2025/05/18 22:06:26 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

char	*strnstr(const char *haystack, const char *needle, size_t len)
{
	int	i;
	int	j;

	if (!*needle)
		return ((char*) haystack);

	i = 0;
	while ()
	{
		j = 0;
		while(needle[j] && hackstack[i + j] && i + j < len && haystack[i + j] == needle[j])
			j++;
		if (!needle[j])
			return ((char*() haystack + i);
		i++;
	}
	return (NULL);
}
