/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrajni <rrajni@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 19:07:07 by rrajni            #+#    #+#             */
/*   Updated: 2025/05/22 19:45:39 by rrajni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
//include <stdio.h>
/*int	main(void)*/
/*{*/
/*	char	a[];*/
/**/
/*	a[] = " I am hah!";*/
/*	printf("%zu\n", ft_strlen(a));*/
/*	return (0);*/
/*}*/
