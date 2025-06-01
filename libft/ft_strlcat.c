/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 22:16:34 by acasper           #+#    #+#             */
/*   Updated: 2025/05/19 00:15:35 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char * restrict dst, const char * restric src, size_t dstsize)
{
	size_t	dstlen;
	size_t	srclen;
	int	i;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if(dstsize <= dstlen)
		return (dstsize + srclen);
	i = 0;
	while (src[i] && dstlen + i < dstsize - 1)
	{
		dst[dstlen + i] = src[i];
		i++;
	}
	dst[dstlen + i] = '\0';
	return (dstlen + srclen);
}

/*
int     main()
{
        return (0);
}
*/
