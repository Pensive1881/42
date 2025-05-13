/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isalnum.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 22:06:05 by acasper           #+#    #+#             */
/*   Updated: 2025/05/12 22:35:43 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	isalnum(char str)
{
	int	i;
	i = 0;
	while (str[i] != '\n')
	{
		if (str[i] < 48)
			return (0);
		else if (str[i] > 57 && str[i] < 65)
			return (0);
		else if (str[i] > 90 && str[i] < 97)
			return (0);
		else if (str[i] > 122)
			return (0);
		i++;
	}
	return (1);
}
