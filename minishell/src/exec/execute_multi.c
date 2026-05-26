/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_multi.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasper <akasper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 21:00:27 by acasper           #+#    #+#             */
/*   Updated: 2026/05/25 19:19:44 by akasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minishell.h"

static int	count_cmds(t_cmd *cmds)
{
	int	count;

	count = 0;
	while (cmds)
	{
		count++;
		cmds = cmds->next;
	}
	return (count);
}

static void	wait_all(t_shell *shell, pid_t *pids, int count)
{
	int	i;
	int	status;

	i = 0;
	while (i < count)
	{
		waitpid(pids[i], &status, 0);
		if (i == count - 1)
		{
			if (WIFEXITED(status))
				shell->last_status = WEXITSTATUS(status);
			else if (WIFSIGNALED(status))
				shell->last_status = 128 + WTERMSIG(status);
		}
		i++;
	}
}

static int	run_pipeline_step(t_shell *shell, t_cmd *cur, int *prev_read,
		pid_t *pid)
{
	int	pipefd[2];
	int	fds[2];

	if (!create_pipe_if_needed(cur, pipefd))
		return (0);
	fds[0] = *prev_read;
	fds[1] = pipefd[1];
	if (!fork_one_pipe(shell, cur, fds, pid))
		return (0);
	parent_close_pipe_fds(cur, prev_read, pipefd);
	return (1);
}

void	execute_multi_command(t_shell *shell, t_cmd *cmds)
{
	int		prev_read;
	pid_t	*pids;
	int		i;
	t_cmd	*cur;

	pids = malloc(sizeof(pid_t) * count_cmds(cmds));
	if (!pids)
		return ;
	prev_read = -1;
	i = 0;
	cur = cmds;
	while (cur)
	{
		if (!run_pipeline_step(shell, cur, &prev_read, &pids[i]))
			return (free(pids));
		cur = cur->next;
		i++;
	}
	close_fd_if_needed(prev_read);
	wait_all(shell, pids, i);
	free(pids);
}
