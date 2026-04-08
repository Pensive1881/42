#include "../includes/minishell.h"
#include <signal.h>

static void sigint_handler(int signo)
{
	(void)signo;
	write(1, "\n", 1);
	rl_one_new_line();
	rl_replace_line("", 0);
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
