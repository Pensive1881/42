/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 20:34:34 by acasper           #+#    #+#             */
/*   Updated: 2025/05/18 20:39:46 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

char	*strchr(const char *str, int c)
{
	int     i;

        if (c == '\0')
		return ((char*) str);
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return ((char*) str[i]);
		i++;
	}
	return (NULL);
}
