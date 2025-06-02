/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 20:27:10 by acasper           #+#    #+#             */
/*   Updated: 2025/05/19 00:11:12 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isalpha(int c)
{
	while (c != '\0')
	{
		if (c < 65)
			return (0);
		else if (c > 90 && c < 97)
			return (0);
		else if (c > 122)
			return (0);
	}
	return (1);
}
/*
int	main(void)
{
	printf("miau: %d\n", isalphaa("miau"));
	printf("mia0: %d\n", isalphaa("mia0"));
	printf("123: %d\n", isalphaa("123"));
	printf("m m: %d\n", isalphaa("m m"));
	return (0);
}
*/
