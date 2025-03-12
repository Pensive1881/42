/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_ft.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owali <owali@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 14:05:19 by owali             #+#    #+#             */
/*   Updated: 2025/02/23 21:45:15 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ft(int *********nbr)
{
	*********nbr = 42;
}

#include <stdio.h>

int	main(void)
{
	int	mynum;
	int	*ptr1;
	int 	**ptr2;
	int	***ptr3;
	int	****ptr4;
	int	*****ptr5;
	int	******ptr6;
	int	*******ptr7;
	int	********ptr8;
	int	*********ptr;

	mynum = 905;
	ptr1 = &mynum;

	ptr2=&ptr1;
	ptr3=&ptr2;
	ptr4=&ptr3;
	ptr5=&ptr4;
	ptr6=&ptr5;
	ptr7=&ptr6;
	ptr8=&ptr7;
	ptr = &ptr8;

	ft_ft(ptr);
	printf("%d", *********ptr);
}

