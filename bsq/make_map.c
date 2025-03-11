/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbigeon <mbigeon@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 04:11:58 by mbigeon           #+#    #+#             */
/*   Updated: 2025/03/11 04:28:15 by mbigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bsq.h>

Grid	*read_grid_from_file(void)
{
	int	fd;
	
	fd = open("example_file", O_RDONLY);
	if (fd == -1)
	{
		write(2, "Error opening file\n", 19);
		exit(1);
	}
}
