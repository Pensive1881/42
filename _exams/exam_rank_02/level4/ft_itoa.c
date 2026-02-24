/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 21:00:04 by acasper           #+#    #+#             */
/*   Updated: 2026/01/20 17:21:52 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	count(int n)
{
	int	count;

	count = 0;
	if (n <= 0)
		count++;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int nbr)
{
	char	*str;
	int	n;
	int	len;

	n = nbr;
	len = count(n);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len--] = '\0';
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	while (n > 0)
	{
		str[len--] = (n % 10) + '0';
		n /= 10;
	}

	return (str);
}
#include <stdio.h>
int     main(void)
{
    printf("424242: %s\n", ft_itoa(424242));
    printf("-424242: %s\n", ft_itoa(-424242));
    printf("0: %s\n", ft_itoa(0));
    printf("-2147483648: %s\n", ft_itoa(-2147483648));
    printf("2147483647: %s\n", ft_itoa(2147483647));

        return (0);
}
