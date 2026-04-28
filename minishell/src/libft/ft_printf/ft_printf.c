/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrajni <rrajni@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 14:22:55 by rrajni            #+#    #+#             */
/*   Updated: 2025/06/23 14:39:32 by rrajni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	va_start(args, format);
	count = 0;
	if (!format)
		return (-1);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			count += print_format(*(++format), args);
		}
		else
		{
			count += write(1, format, 1);
		}
		format++;
	}
	va_end(args);
	return (count);
}

int	print_format(char specifier, va_list args)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += print_char(va_arg(args, int));
	else if (specifier == 's')
		count += print_string(va_arg(args, const char *));
	else if (specifier == 'd' || specifier == 'i')
		count += print_number(va_arg(args, int));
	else if (specifier == 'X')
		count += print_hexa(va_arg(args, unsigned int), 1);
	else if (specifier == 'x')
		count += print_hexa(va_arg(args, unsigned int), 0);
	else if (specifier == '%')
		count += write(1, "%", 1);
	else if (specifier == 'u')
		count += print_unumber(va_arg(args, unsigned int));
	else if (specifier == 'p')
		count += print_pointer(va_arg(args, void *));
	else
		count += write(1, &specifier, 1);
	return (count);
}

int	print_char(int c)
{
	int	count;

	count = 0;
	count = write(1, &c, 1);
	return (count);
}

int	print_hexa(unsigned int n, int uppercase)
{
	int		count;
	char	*digits;

	count = 0;
	if (uppercase)
		digits = "0123456789ABCDEF";
	else
		digits = "0123456789abcdef";
	if (n >= 16)
		count += print_hexa(n / 16, uppercase);
	count += write(1, &digits[n % 16], 1);
	return (count);
}

int	print_number(int n)
{
	int		count;
	char	digit;

	count = 0;
	if (n == -2147483648)
	{
		count = write(1, "-2147483648", 11);
		return (count);
	}
	if (n < 0)
	{
		count = write(1, "-", 1);
		n = -n;
	}
	if (n >= 10)
	{
		count += print_number(n / 10);
	}
	digit = n % 10 + '0';
	count += write(1, &digit, 1);
	return (count);
}
/*
#include <stddef.h>
int main(void)
{
	int ret1, ret2;
	int x = 1337;

	ret1 = printf("%c\n", 'A');
	ret2 = ft_printf("%c\n", 'A');
	printf("%d\n%d\n\n", ret1, ret2);

	ret1 = printf("%s\n", "Hello");
	ret2 = ft_printf("%s\n", "Hello");
	printf("%d\n%d\n\n", ret1, ret2);

	ret1 = printf("%d\n", -42);
	ret2 = ft_printf("%d\n", -42);
	printf("%d\n%d\n\n", ret1, ret2);

	ret1 = printf("%i\n", 42);
	ret2 = ft_printf("%i\n", 42);
	printf("%d\n%d\n\n", ret1, ret2);

	ret1 = printf("%u\n", 3000000000u);
	ret2 = ft_printf("%u\n", 3000000000u);
	printf("%d\n%d\n\n", ret1, ret2);

	ret1 = printf("%x\n", 305441741);
	ret2 = ft_printf("%x\n", 305441741);
	printf("%d\n%d\n\n", ret1, ret2);

	ret1 = printf("%X\n", 305441741);
	ret2 = ft_printf("%X\n", 305441741);
	printf("%d\n%d\n\n", ret1, ret2);

	ret1 = printf("%%\n");
	ret2 = ft_printf("%%\n");
	printf("%d\n%d\n\n", ret1, ret2);

	ret1 = printf("%p\n", &x);
	ret2 = ft_printf("%p\n", &x);
	printf("%d\n%d\n\n", ret1, ret2);

	ret1 = printf("%s\n", "");
	ret2 = ft_printf("%s\n", "");
	printf("%d\n%d\n\n", ret1, ret2);

	return 0;
}
*/
