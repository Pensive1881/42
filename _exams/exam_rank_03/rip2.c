/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rip2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 18:33:24 by acasper           #+#    #+#             */
/*   Updated: 2026/03/12 18:33:25 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <fcntl.h>

int	main(int argc, char **argv)
{
	int	fd1;
	int	fd2;
	char	buffer[1024];
	int	bytes;

	if (argc != 3)
		return (1);
	fd1 = open(argv[1], O_RDONLY);
	if (fd1 < 0)
		return (1);
	fd2 = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd1 < 0)
	{
		close(fd2);
		return (1);
	}
	while ((bytes = read(fd1, buffer, 1024)) > 0)
		write(fd2, buffer, bytes);
	close(fd1);
	close(fd2);
	return (0);
}

