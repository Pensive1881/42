/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 18:01:09 by acasper           #+#    #+#             */
/*   Updated: 2025/08/21 18:22:43 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	alpha_mirror(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = 'Z' - str[i] + 'A';
		else if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = 'z' - str[i] + 'a';
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
		alpha_mirror(argv[1]);
	return (0);
}

