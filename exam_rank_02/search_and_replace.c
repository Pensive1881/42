/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 17:06:09 by acasper           #+#    #+#             */
/*   Updated: 2025/08/20 17:10:20 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	search_and_replace(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		
		i++;
	}
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	if (argc != 4)
		write(1, "\n", 1);
	else
		search_and_replace(argv[1]);

	return (0);
}

