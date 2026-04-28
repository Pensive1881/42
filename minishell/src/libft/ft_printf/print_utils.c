/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrajni <rrajni@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 15:01:49 by rrajni            #+#    #+#             */
/*   Updated: 2025/06/23 14:59:24 by rrajni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_string(const char *str)
{
	int	count;

	if (!str)
		str = "(null)";
	count = 0;
	while (*str)
	{
		write(1, str, 1);
		str++;
		count++;
	}
	return (count);
}

int	print_unumber(unsigned int n)
{
	int		count;
	char	digit;
	long	num;

	num = n;
	count = 0;
	if (num >= 10)
	{
		count += print_number(n / 10);
	}
	digit = num % 10 + '0';
	count += write(1, &digit, 1);
	return (count);
}

int	print_pointer(void *ptr)
{
	int			count;
	uintptr_t	n;

	count = 0;
	if (ptr == NULL)
		return (write(1, "(nil)", 5));
	n = (uintptr_t)ptr;
	count += write(1, "0x", 2);
	count += print_hexa_pointer(n);
	return (count);
}

int	print_hexa_pointer(uintptr_t n)
{
	int		count;
	char	*digits;

	count = 0;
	digits = "0123456789abcdef";
	if (n >= 16)
		count += print_hexa_pointer(n / 16);
	count += write(1, &digits[n % 16], 1);
	return (count);
}
