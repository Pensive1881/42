/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 19:30:24 by acasper           #+#    #+#             */
/*   Updated: 2025/06/09 18:24:34 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putptr(unsigned long ptr)
{
	int	count;
	char	*base;
	char	buffer[16];
	unsigned long	n;
	int	i;

	count = 0;
	count += ft_putstr("0x");
	if (ptr == 0)
		return (count + ft_putchar('0'));

	n = ptr;
	base = "0123456789abcdef";
	i = 0;
	while (n > 0)
	{
		buffer[i++] = base[n % 16];
		n /= 16;
	}
	while (--i >= 0)
		count += ft_putchar(buffer[i]);

	return (count);
}
