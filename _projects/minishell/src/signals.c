/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasper <akasper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 16:30:13 by rrajni            #+#    #+#             */
/*   Updated: 2026/05/30 22:47:09 by akasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include <readline/readline.h>
#include <signal.h>
#include <unistd.h>

void					rl_replace_line(const char *text, int clear_undo);

volatile sig_atomic_t	g_signal = 0;

static void	sigint_handler(int signo)
{
	g_signal = signo;
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
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
