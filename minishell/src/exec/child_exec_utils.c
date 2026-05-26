/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_exec_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 11:24:59 by acasper           #+#    #+#             */
/*   Updated: 2026/05/26 11:25:02 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minishell.h"

static void	dup_child_fd(t_shell *shell, int old_fd, int new_fd)
{
	if (old_fd != -1 && old_fd != new_fd)
	{
		if (dup2(old_fd, new_fd) < 0)
		{
			perror("dup2");
			clean_exit(shell, 1);
		}
	}
}

void	dup_child_fds(t_shell *shell, int in_fd, int out_fd)
{
	dup_child_fd(shell, in_fd, STDIN_FILENO);
	dup_child_fd(shell, out_fd, STDOUT_FILENO);
}

void	exit_child_builtin(t_shell *shell, t_cmd *cmd)
{
	int	status;

	status = execute_buildin(shell, cmd);
	clean_exit(shell, status);
}

void	exec_child_external(t_shell *shell, t_cmd *cmd)
{
	char	*path;

	path = find_command_path(cmd->argv[0], shell->env);
	if (!path)
	{
		print_exec_error(cmd->argv[0]);
		clean_exit(shell, 127);
	}
	execve(path, cmd->argv, shell->env);
	perror("execve");
	free(path);
	clean_exit(shell, 126);
}
