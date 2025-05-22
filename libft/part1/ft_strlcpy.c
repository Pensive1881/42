/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 22:15:42 by acasper           #+#    #+#             */
/*   Updated: 2025/05/19 00:16:21 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include libft.h

size_t  ft_strlcpy(char * restrict dst, const char * restric src, size_t dstsize);
{
	int	i;

	i = 0;
	if (dstsize > 0)
	{
		while (src[i] && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

/*
int     main()
{
        return (0);
}
*/
