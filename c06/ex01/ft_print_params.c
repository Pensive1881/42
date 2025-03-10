/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 17:46:54 by acasper           #+#    #+#             */
/*   Updated: 2025/03/10 18:30:17 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	stupid;
	int	i;
	int	j;

	if (argc < 0)
		stupid = 0;
	i = 0;
	j = 0;
	while (argv[i][j])
	{
		j = 0;
		while (argv[i][j])
		{
			write(1, &argv[i][j], 1);
			i++;
		}
		j++;
	}
	return (0);
}
