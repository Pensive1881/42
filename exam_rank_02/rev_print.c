/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 15:48:21 by acasper           #+#    #+#             */
/*   Updated: 2025/08/20 15:48:24 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rev_print(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (str[i] >= 0)
	{
		write(1, &str[i] 1);
		i--;
	}
	write(1, '\n', 1);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		write(1, '\n', 1);
	return (0);
}
