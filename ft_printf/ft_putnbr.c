/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 19:29:43 by acasper           #+#    #+#             */
/*   Updated: 2025/06/06 21:47:16 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	putnbr(int n)
{
	char *str = ft_itoa(n);
	int len = ft_strlen(str);
	ft_putstr_fd(str, 1);
	free(str);
	return (len);
}

