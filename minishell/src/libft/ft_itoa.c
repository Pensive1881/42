/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrajni <rrajni@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 11:11:53 by rrajni            #+#    #+#             */
/*   Updated: 2025/06/03 15:28:24 by rrajni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digit(long nb)
{
	int	count;

	count = 0;
	if (nb == 0)
		return (1);
	else if (nb < 0)
	{
		count = 1;
		nb = -nb;
	}
	while (nb > 0)
	{
		nb /= 10;
		count++;
	}
	return (count);
}

static void	fill_in(long nb, char *s, int len)
{
	int	sign;

	if (nb == 0)
	{
		s[0] = '0';
		return ;
	}
	sign = 0;
	if (nb < 0)
	{
		sign = 1;
		nb = -nb;
	}
	while (nb > 0)
	{
		s[--len] = (nb % 10) + '0';
		nb /= 10;
	}
	if (sign)
		s[0] = '-';
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	long	nb;

	nb = n;
	len = count_digit(nb);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	fill_in(n, str, len);
	return (str);
}
/*#include <stdio.h>
int	main(void)
{
	printf("%s\n", ft_itoa(0));
	printf("%s\n", ft_itoa(456));
	printf("%s\n", ft_itoa(-123));
	return (0);
}*/
