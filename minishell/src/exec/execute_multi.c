/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_multi.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasper <akasper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 21:00:27 by acasper           #+#    #+#             */
/*   Updated: 2026/05/22 19:42:00 by akasper          ###   ########.fr       */
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

void	execute_multi_command(t_shell *shell, t_cmd *cmds)
{
	int		prev_read;
	int		pipefd[2];
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
		if (!create_pipe_if_needed(cur, pipefd))
			return (free(pids));
		if (!fork_one_pipe(shell, cur, prev_read, pipefd, &pids[i]))
			return (free(pids));
		parent_close_pipe_fds(cur, &prev_read, pipefd);
		cur = cur->next;
		i++;
	}
	close_fd_if_needed(prev_read);
	wait_all(shell, pids, i);
	free(pids);
}
