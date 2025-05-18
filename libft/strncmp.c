/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 22:18:33 by acasper           #+#    #+#             */
/*   Updated: 2025/05/18 21:57:46 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	strncmp(const char *str1, const char *str2, size_t n)
{
	int	i;

	i = 0;
	while(i < n)
	{
		if (str[i] != str2[i] || str1[i] == '\0' || str2[i] == '\0')
			return ((unsigned char) str1[i] - (unsigned char) str2[i]);
		i++;
	}
	return (0);
}
