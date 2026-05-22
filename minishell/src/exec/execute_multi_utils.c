/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_multi_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 18:43:41 by acasper           #+#    #+#             */
/*   Updated: 2026/05/22 18:43:46 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minishell.h"

static int	create_pipe_if_needed(t_cmd *cmd, int pipefd[2])
{
	if (cmd->next && pipe(pipefd) < 0)
	{
		perror("pipe");
		return (0);
	}
	return (1);
}

static void	run_child(t_shell *shell, t_cmd *cmd, int prev_read, int pipefd[2])
{
	if (cmd->next)
		child_exec(shell, cmd, prev_read, pipefd[1]);
	else
		child_exec(shell, cmd, prev_read, STDOUT_FILENO);
}

static int	fork_one(t_shell *shell, t_cmd *cmd, int prev_read, int pipefd[2],
		pid_t *pid)
{
	*pid = fork();
	if (*pid < 0)
	{
		perror("fork");
		return (0);
	}
	if (*pid == 0)
		run_child(shell, cmd, prev_read, pipefd);
	return (1);
}

static void	parent_close_fds(t_cmd *cmd, int *prev_read, int pipefd[2])
{
	close_fd_if_needed(*prev_read);
	if (cmd->next)
	{
		close(pipefd[1]);
		*prev_read = pipefd[0];
	}
}
