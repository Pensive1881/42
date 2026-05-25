/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_multi_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasper <akasper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 18:43:41 by acasper           #+#    #+#             */
/*   Updated: 2026/05/25 19:29:50 by akasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minishell.h"

int	create_pipe_if_needed(t_cmd *cmd, int pipefd[2])
{
	if (cmd->next && pipe(pipefd) < 0)
	{
		perror("pipe");
		return (0);
	}
	return (1);
}

void	run_pipe_child(t_shell *shell, t_cmd *cmd, int prev_read, int pipefd[2])
{
	if (cmd->next)
		child_exec(shell, cmd, prev_read, pipefd[1]);
	else
		child_exec(shell, cmd, prev_read, STDOUT_FILENO);
}

int	fork_one_pipe(t_shell *shell, t_cmd *cmd, int fds[2], pid_t *pid)
{
	*pid = fork();
	if (*pid < 0)
	{
		perror("fork");
		return (0);
	}
	if (*pid == 0)
		child_exec(shell, cmd, fds[0], fds[1]);
	return (1);
}

void	parent_close_pipe_fds(t_cmd *cmd, int *prev_read, int pipefd[2])
{
	close_fd_if_needed(*prev_read);
	if (cmd->next)
	{
		close(pipefd[1]);
		*prev_read = pipefd[0];
	}
}
