/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 19:01:11 by acasper           #+#    #+#             */
/*   Updated: 2025/09/17 20:12:27 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

static int	send_char(pid_t pid, unsigned char ch)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (kill(pid, ((ch >> i) & 1) ? SIGUSR2 : SIGUSR1) == -1)
			return (-1);
		usleep(100);
		i--;
	}
	return (0);
}

static int	send_str(pid_t pid, const char *str)
{
	while (*str)
	{
		if (send_char(pid, (unsigned char)*str++) == -1)
			return (-1);
	}
	return (send_char(pid, 0));
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc != 3 || !ft_strlen(argv[2]))
		return (1);
	pid = (pid_t)ft_atoi(argv[1]);
	if (pid <= 0)
		return (1);
	if (send_str(pid, argv[2]) == -1)
		return (1);
	return (0);
}
