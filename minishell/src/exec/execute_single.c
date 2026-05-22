/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_single.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasper <akasper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 21:00:07 by acasper           #+#    #+#             */
/*   Updated: 2026/05/04 18:06:12 by akasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minishell.h"

static void	exec_external(t_cmd *cmd, t_shell *shell)
{
	char	*path;

	if (!cmd || !cmd->argv || !cmd->argv[0])
	{
		free_env(shell->env);
		free_cmds(shell->cmds);
		free_tokens(shell->tokens);
		free(shell->input);
		exit(1);
	}
	path = find_command_path(cmd->argv[0], shell->env);
	if (!path)
	{
		print_exec_error(cmd->argv[0]);
		free_env(shell->env);
		free_cmds(shell->cmds);
		free_tokens(shell->tokens);
		free(shell->input);
		exit(127);
	}
	execve(path, cmd->argv, shell->env);
	perror("execve");
	free_env(shell->env);
	free_cmds(shell->cmds);
	free_tokens(shell->tokens);
	free(shell->input);
	free(path);
	exit(126);
}

static int	save_stdio(int saved[2])
{
	saved[0] = dup(STDIN_FILENO);
	saved[1] = dup(STDOUT_FILENO);
	if (saved[0] < 0 || saved[1] < 0)
		return (0);
	return (1);
}

static void	restore_stdio(int saved[2])
{
	dup2(saved[0], STDIN_FILENO);
	dup2(saved[1], STDOUT_FILENO);
	close(saved[0]);
	close(saved[1]);
}

void	execute_single_command(t_shell *shell, t_cmd *cmd)
{
	pid_t	pid;
	int		status;
	int		saved[2];

	if (!cmd || !cmd->argv || !cmd->argv[0])
		return ;
	if (is_buildin(cmd->argv[0]))
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
		return ;
	}
	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		return ;
	}
	if (pid == 0)
	{
		setup_child_signals();
		if (!apply_redirections(cmd->redirs))
			exit(1);

		exec_external(cmd, shell);
	}
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		shell->last_status = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
		shell->last_status = 128 + WTERMSIG(status);
}
