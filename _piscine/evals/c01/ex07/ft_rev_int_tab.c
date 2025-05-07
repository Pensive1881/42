/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owali <owali@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 19:35:35 by owali             #+#    #+#             */
/*   Updated: 2025/02/23 21:54:11 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	*copy;
	int	*copy2;
	int	temp;

	copy = tab;
	copy2 = tab + size - 1;
	while (copy <= copy2)
	{
		temp = *copy;
		*copy = *copy2;
		*copy2 = temp;
		copy++;
		copy2--;
	}
}

#include "stdio.h"
int main()
{
	int int_ptr[]={8,9,1};
	int size=sizeof(int_ptr)/sizeof(int_ptr[0]);
//	int *int_ptr;
//	int_ptr=i;
	ft_rev_int_tab(int_ptr,size);
	int *ptr = int_ptr;
	int i=0;
	while (i!=size)
	{
		printf("%d", *ptr);
		ptr++;
		i++;

	}
}
