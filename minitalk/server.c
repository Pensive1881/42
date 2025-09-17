/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 19:00:30 by acasper           #+#    #+#             */
/*   Updated: 2025/09/17 20:32:18 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

static void	sig_handler(int sig, siginfo_t *info, void *ucontext)
{
	static unsigned char	ch = 0;
	static int	bit = 0;

	(void)info;
	(void)ucontext;

	ch <<= 1;
	if (sig == SIGUSR2)
		ch |= 1;

	bit++;
	if (bit == 8)
	{
		if (ch == '\0')
			write(1, "\n", 1);
		else
			write(1, &ch, 1);
		ch = 0;
		bit = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_putstr_fd("Server PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);

	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = sig_handler;
	if (sigaction(SIGUSR1, &sa, 0) == -1 || sigaction(SIGUSR2, &sa, 0) == -1)
	{
		ft_putstr_fd("sigaction error\n", 2);
		return (1);
	}

	while (1)
		pause();
}

