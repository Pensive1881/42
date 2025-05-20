/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 22:16:34 by acasper           #+#    #+#             */
/*   Updated: 2025/05/18 22:46:42 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <string.h>

size_t	strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	strlcat(char *dest, const char *scr, size_t dest_size)
{
	size_t	dest_len;
	size_t	src_len;
	int	i;

	dest_len = strlen(dest);
	src_len = str(scr);
	if(destlen < = dest_len)
		return (dest_size + scr_len);
	i = 0;
	while (src[i] && dest_len + i < dest_size - 1)
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest_len + scr_len);
}
