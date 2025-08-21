/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 16:55:26 by acasper           #+#    #+#             */
/*   Updated: 2025/08/21 17:03:48 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	rotone(char *str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		if ((str[i] >= 'A' && str[i] <= 'Y') || (str[i] >= 'a' && str[i] <= 'y'))
		{
			str[i] += 1;	
			write(1, &str[i], 1);
		}
		else if (str[i] == 'Z')
			write(1, "A", 1);
		else if (str[i] == 'z')
			write(1, "a", 1);
		else
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
		rotone(argv[1]);
	return (0);
}
