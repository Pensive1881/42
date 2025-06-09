/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsign.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 19:30:40 by acasper           #+#    #+#             */
/*   Updated: 2025/06/09 17:09:13 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putunsign(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
		count += ft_putunsign(n / 10);
	count += ft_putunsign((n % 10) + '0');
	return (count);
}
