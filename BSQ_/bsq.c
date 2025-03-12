/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbigeon <mbigeon@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 19:34:19 by mbigeon           #+#    #+#             */
/*   Updated: 2025/03/12 19:34:21 by mbigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "bsq.h"

int	main(void)
{
	int		height;
	int		width;
	int		len;
	int		i;
	char	**map;

	i = 0;
	get_data("example_file", &height, &width, &map);
	while (i < height)
	{
		len = 0;
		while (map[i][len])
			len++;
		write(1, map[i], len);
		write(1, "\n", 1);
		free(map[i]);
		i++;
	}
	free(map);
	return (0);
}
