/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 15:36:00 by acasper           #+#    #+#             */
/*   Updated: 2025/06/06 17:41:05 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <unistd.h>
#include <stdarg.h>

void	find_format(char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
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
	i = 0;
	while (format[i])
	{
		if (
	}
	return (0);
}


#include <stdio.h>

int	main(void)
{
	ft_printf("Hey! call me %s because I'm at %s", "miaumeow", 42);
	return (0);
}

