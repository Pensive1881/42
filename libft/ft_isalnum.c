/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 22:06:05 by acasper           #+#    #+#             */
/*   Updated: 2025/06/01 22:55:06 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isalnum(char c)
{
	int	i;
	i = 0;
	while (c != '\n')
	{
		if (c < 48)
			return (0);
		else if (c > 57 && c < 65)
			return (0);
		else if (c > 90 && c < 97)
			return (0);
		else if (c > 122)
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
