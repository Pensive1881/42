/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_single_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 11:17:40 by acasper           #+#    #+#             */
/*   Updated: 2026/05/26 11:17:43 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minishell.h"

void	clean_exit(t_shell *shell, int status)
{
	if (shell->pids)
		free(shell->pids);
	free_env(shell->env);
	free_cmds(shell->cmds);
	free_tokens(shell->tokens);
	free(shell->input);
	exit(status);
}

int	save_stdio(int saved[2])
{
	saved[0] = dup(STDIN_FILENO);
	saved[1] = dup(STDOUT_FILENO);
	if (saved[0] < 0 || saved[1] < 0)
		return (0);
	return (1);
}

void	restore_stdio(int saved[2])
{
	dup2(saved[0], STDIN_FILENO);
	dup2(saved[1], STDOUT_FILENO);
	close(saved[0]);
	close(saved[1]);
}

void	run_saved_builtin(t_shell *shell, t_cmd *cmd, int saved[2])
{
	if (!save_stdio(saved))
	{
		perror("dup");
		shell->last_status = 1;
		return ;
	}
	if (!apply_redirections(cmd->redirs))
		shell->last_status = 1;
	else
		shell->last_status = execute_buildin(shell, cmd);
	restore_stdio(saved);
}

void	wait_for_child(t_shell *shell, pid_t pid)
{
	int	status;

	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		shell->last_status = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
		shell->last_status = 128 + WTERMSIG(status);
}
