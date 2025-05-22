/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 20:34:34 by acasper           #+#    #+#             */
/*   Updated: 2025/05/19 00:13:56 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int     i;

        if (c == '\0')
		return ((char*) s);
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return ((char*) s[i]);
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
