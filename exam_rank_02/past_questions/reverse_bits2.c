/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 13:49:29 by acasper           #+#    #+#             */
/*   Updated: 2026/02/24 13:49:38 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned char	reverse_bits(unsigned char octet)
{
	unsigned int	result;
	int	i;

	i = 8;
	while (i--)
	{
		result = (result << 1) | (octet &)
		octet = octet >> 1;
	}
	return (result);
}

