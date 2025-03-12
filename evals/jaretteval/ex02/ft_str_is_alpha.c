/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 17:43:58 by acasper           #+#    #+#             */
/*   Updated: 2025/03/04 17:08:50 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_alpha(char *str)
{
	while (*str != '\0')
	{
		if (*str < 65)
		{
			write(1, "\n0", 2);
			return (0);
		}
		else if (*str > 90 && *str < 97)
		{
			write(1, "\n0", 2);
			return (0);
		}
		else if (*str > 122)
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
	char	*string;

	string = "/";
	ft_str_is_alpha(argv[1]);
}

