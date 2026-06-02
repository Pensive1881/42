/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrajni <rrajni@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 15:14:36 by rrajni            #+#    #+#             */
/*   Updated: 2025/06/23 15:14:39 by rrajni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	print_char(int c);
int	print_format(char specifier, va_list args);
int	print_hexa(unsigned int n, int uppercase);
int	print_hexa_pointer(uintptr_t n);
int	print_number(int n);
int	print_percent(void);
int	print_pointer(void *ptr);
int	print_string(const char *str);
int	print_unumber(unsigned int u);

#endif
