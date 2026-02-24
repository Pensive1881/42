/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_13.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 15:48:05 by acasper           #+#    #+#             */
/*   Updated: 2025/08/20 16:44:34 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	rot_13(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= 'A' && str[i] <= 'M') || (str[i] >= 'a' && str[i] <= 'm'))
			str[i] += 13;
		else if ((str[i] >= 'N' && str[i] <= 'Z') || (str[i] >= 'n' && str[i] <= 'z'))
			str[i] -= 13;
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}	

int	main(int argc, char **argv)
{
	if (argc != 2)
		write(1, "\n", 1);
	else
		rot_13(argv[1]);
	return (0);
}
