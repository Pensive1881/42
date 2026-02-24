/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 16:52:54 by acasper           #+#    #+#             */
/*   Updated: 2025/06/18 17:30:43 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(void)
{
		char *line;
		int fd;

		fd = open("main.c", O_RDONLY);

		

		while ((line = get_next_line(fd)) != NULL)
		{
				printf("%s", line);
		}
}
