/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owali <owali@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 18:32:03 by owali             #+#    #+#             */
/*   Updated: 2025/02/23 22:00:51 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int	*b)
{
	int	temp_a;
	int	temp_b;

	temp_a = *a;
	temp_b = *b;
	*a = temp_a / temp_b;
	*b = temp_a % temp_b;
}

#include "stdio.h"
int main()
{
	int	a;
	int	b;
	int	*div;
	int	*mod;

	a = 41;
	b = 7;
	
	div=&a;
	mod=&b;
	ft_ultimate_div_mod(div, mod);
	printf("division : %d  %d",*div,*mod );
}

