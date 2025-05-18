/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strrchr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 20:44:19 by acasper           #+#    #+#             */
/*   Updated: 2025/05/18 20:47:08 by acasper          ###   ########.fr       */
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
