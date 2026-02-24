/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 17:06:09 by acasper           #+#    #+#             */
/*   Updated: 2025/08/21 17:58:26 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	search_and_replace(char *str, char c1, char c2)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c1)
			write(1, &c2, 1);
		else
			write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	if (argc != 4 || argv[2][1] || argv[3][1])
		write(1, "\n", 1);
	else
		search_and_replace(argv[1], argv[2][0], argv[3][0]);

	return (0);
}

