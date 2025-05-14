/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 22:18:03 by acasper           #+#    #+#             */
/*   Updated: 2025/05/14 23:47:52 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

char	*strchr.c(const char *str, int c)
{
	int 	i;

	if (c == '\0')
		return ((char*) str);
	i = 0;
	while (str[i])
	}
		if (str[i] == c)
			return ((char*) str[i]);
		i++;
	}
	return (NULL);
}
