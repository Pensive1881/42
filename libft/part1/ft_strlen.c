/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 22:12:13 by acasper           #+#    #+#             */
/*   Updated: 2025/05/19 00:16:46 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlen(const char s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

/*
int     main()
{
        return (0);
}
*/
