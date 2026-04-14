/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_single.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 21:00:07 by acasper           #+#    #+#             */
/*   Updated: 2026/03/31 21:00:12 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minishell.h"

static void	exec_external(t_cmd *cmd, char **envp)
{
	char *path;

	if (!cmd || !cmd->argv || !cmd->argv[0])
		exit(1);
	path = find_command_path(cmd->argv[0], envp);
	if (!path)
	{
		print_exec_error(cmd->argv[0]);
		exit(127);
	}
	execve(path, cmd->argv, envp);
	perror("execve");
	free(path);
	exit(126);
}

void    execute_single_command(t_shell *shell, t_cmd *cmd)
{
	pid_t pid;
	int	status;

	if (!cmd || !cmd->argv || !cmd->argv[0])
		return ;
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
		if (is_buildin(cmd->argv[0]))
			exit(execute_buildin(shell, cmd));

		exec_external(cmd, shell->env);
	}
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		shell->last_status = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
		shell->last_status = 128 + WTERMSIG(status);
}
