/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 22:06:05 by acasper           #+#    #+#             */
/*   Updated: 2025/05/19 00:10:54 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isalnum(char c)
{
	int	i;
	i = 0;
	while (c[i] != '\n')
	{
		if (c[i] < 48)
			return (0);
		else if (c[i] > 57 && c[i] < 65)
			return (0);
		else if (c[i] > 90 && c[i] < 97)
			return (0);
		else if (c[i] > 122)
			return (0);
		i++;
	}
	return (1);
}

/*
int     main()
{
        return (0);
}
*/
