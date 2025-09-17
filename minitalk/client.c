/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 19:01:11 by acasper           #+#    #+#             */
/*   Updated: 2025/09/17 18:56:31 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

static void	signal_handler(int sig)
{
	static int	received;

	received = 0;
	if (sig == SIGUSR1)
		++received;
	else
	{
		ft_putnbr_fd(received, 1);
		ft_putchar_fd('\n', 1);
		exit(0);
	}
}

void	ft_kill(int pid, char *str)
{
	int	i;
	int	c;

	while (*str)
	{
		i = 8;
		c = *str++;
		while (i--)
		{
			if (c >> i & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(200);
		}
		i++;
	}
	i = 8;
	while (i--)
	{
		kill(pid, SIGUSR1);
		usleep(200);
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;

	if (argc != 3 || !ft_strlen(argv[2]))
		return (1);
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	ft_kill(ft_atoi(argv[1]), argv[2]);
	while (1)
		pause();
	return (0);
}
