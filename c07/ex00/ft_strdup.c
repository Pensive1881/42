/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 18:56:14 by acasper           #+#    #+#             */
/*   Updated: 2025/03/11 22:45:48 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int	len;

	len = 0;
	while (src[len])
		len++;

	src[] = (char*)malloc(1 + 1);

	return (src);
}

#include <stdio.h>
int	main(void)
{
	char	c;

	c = "x";
	*ft_strdup(c);
}

