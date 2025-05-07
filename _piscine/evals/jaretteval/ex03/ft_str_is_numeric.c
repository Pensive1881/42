/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 17:51:05 by acasper           #+#    #+#             */
/*   Updated: 2025/03/04 17:10:45 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>


int	ft_str_is_numeric(char *str)
{
	while (*str != '\0')
	{
		if (*str < 48)
		{
			write(1, "\n0", 2);
			return (0);
		}
		else if (*str > 57)
		{
			write(1, "\n0", 2);
			return (0);
		}
		str++;
	}
	write(1, "\n1", 2);
	return (1);
}

#include <stdio.h>

int	main(int argc, char *argv[])
{
	(void)argc;
	ft_str_is_numeric(argv[1]);
}
