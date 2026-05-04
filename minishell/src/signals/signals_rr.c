//ctrl + c
/*
 * this has to cancel the current input, prints newline, show fresh prompt
 * while the command is running, intrupt the command(default beha)
*/
//ctrl+\,
/*
 * ingore completely?
 * while command is running, "core dump message"(default beh)
*/
//ctrl+d
/*
 *already handeled by readline returning NUll, just exit the shell
 * */

void	setup_signals(void)
{
	struct	sigaction	sa;

	sa.sa_handler = handle_sigint;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigation(SIGINT, &sa, NULL);
	sa.sa_handler = SIG_IGN;
	sigaction(SIGQUIT, &sa, NULL);
}

void	handle_sigint(int sig)
{
	(void)sig;
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}
