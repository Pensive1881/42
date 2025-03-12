/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owali <owali@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 18:32:03 by owali             #+#    #+#             */
/*   Updated: 2025/02/24 17:02:13 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

#include "stdio.h"
int main()
{
	int	a;
	int	b;
	int	*div;
	int	*mod;

	a = 11;
	b = 10;
	
	div=&a;
	mod=&b;
	ft_div_mod(a, b, *div, *mod);
	printf("division : %d  %d",*div,*mod );
}

