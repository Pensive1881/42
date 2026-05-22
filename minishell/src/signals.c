/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrajni <rrajni@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 16:30:13 by rrajni            #+#    #+#             */
/*   Updated: 2026/05/21 13:38:38 by rrajni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include <signal.h>
#include <readline/readline.h>

void	rl_replace_line(const char *text, int clear_undo);

volatile sig_atomic_t	g_signal = 0;

static	void	sigint_handler(int signo)
{
	g_signal = signo;
	write(1, "\n", 1);
	rl_on_new_line();
// removed for mac compiling, readline.h linking
//	rl_replace_line("", 0);
	rl_redisplay();
}

void	setup_signals(void)
{
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, SIG_IGN);
}

void	setup_child_signals(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
}
