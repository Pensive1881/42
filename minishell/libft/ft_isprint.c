/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrajni <rrajni@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 18:55:20 by rrajni            #+#    #+#             */
/*   Updated: 2025/05/12 19:06:09 by rrajni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}

/*#include <stdio.h>

int	main(void)
{
	int	a = '	';
	int	b = '=';

	printf("%d\n", ft_isprint(a));
	printf("%d\n", ft_isprint(b));
	return (0);
}*/
