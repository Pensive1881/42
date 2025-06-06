/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 15:36:00 by acasper           #+#    #+#             */
/*   Updated: 2025/06/06 18:40:19 by acasper          ###   ########.fr       */
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
		return ();
	else if (c == 'x' || c == 'X')
		return ();
	else if (c == 'u')
		return ();
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
	ft_printf("Hey! call me %s because I'm at %s", "miaumeow", 42);
	return (0);
}

