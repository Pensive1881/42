#include "../../minishell.h"

void	clean_exit(t_shell *shell, int status)
{
	free_env(shell->env);
	free_cmds(shell->cmds);
	free_tokens(shell->tokens);
	free(shell->input);
	exit(status);
}

int	save_stdio(int saved[2])
{
	
}

void	restore_stdio(int saved[2])
{
	
}

void	run_saved_buildtin(t_Shell *shell, t_cmd *cmd, int saved[2])
{
	
}

void	wait_for_child(t_shell *shell, pid_t pid)
{
	
}
