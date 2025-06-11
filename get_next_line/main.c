/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 14:27:37 by acasper           #+#    #+#             */
/*   Updated: 2025/06/11 14:35:30 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <fcnl.h>
#include <unistd.h>
#include "get_next_line.h"

int	main()
{
	int	fd = open("text.txt", O_RDONLY);
	char	*line;

	if (fd < 0)
	{
		printf("Error");
		return (1);
	}

	line = get_next_line;
	while (line != NULL)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);

	return (0);
}
