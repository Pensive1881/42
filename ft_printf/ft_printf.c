/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 15:36:00 by acasper           #+#    #+#             */
/*   Updated: 2025/06/06 19:07:36 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	find_format(char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar_fd(va_arg(args, int)));
	else if (c == 's')
		return (ft_putstr_fd(va_arg(args, char *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr_fd(va_arg(args, int)));
	else if (c == 'p')
		return (ft_putptr(va_arg(args, void *)));
	else if (c == 'x')
		return (ft_puthex(va_arg(args, unsigned int), 0));
	else if (c == 'X')
		return (ft_puthex(va_arg(args, unsigned int), 1));
	else if (c == 'u')
		return (ft_putunsig(args, unsigned int)));
	else if (c == '%')
		return (write(1, "%", 1));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int	count;
	int	i;

	count = 0;
	va_start(args, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
			count += find_format(format[++i], args);
		else
			count += write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}


#include <stdio.h>

int	main(void)
{
	ft_printf("Hey! call me %s because I'm at %d", "miaumeow", 42);
	return (0);
}

