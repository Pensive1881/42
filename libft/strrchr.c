/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strrchr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 22:49:01 by acasper           #+#    #+#             */
/*   Updated: 2025/05/15 00:07:49 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

char	*strrchr(const char *str, int c)
{
	int	i;

	if (c == '\0')
		return ((char*) str);
	i = 0;
	while (str[i])
	{

	}
	return (0);
}
