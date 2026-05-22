/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_multi.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 21:00:27 by acasper           #+#    #+#             */
/*   Updated: 2026/03/31 21:00:31 by acasper          ###   ########.fr       */
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
	int		count;
	t_cmd	*cur;

	count = count_cmds(cmds);
	pids = malloc(sizeof(pid_t) * count);
	if (!pids)
		return ;
	prev_read = -1;
	i = 0;
	cur = cmds;
	while (cur)
	{
		if (cur->next && pipe(pipefd) < 0)
		{
			close_fd_if_needed(prev_read);
			free(pids);
			perror("pipe");
			return ;
		}
		pids[i] = fork();
		if (pids[i] < 0)
		{
			close_fd_if_needed(prev_read);
			if (cur->next)
			{
				close(pipefd[0]);
				close(pipefd[1]);
			}
			free(pids);
			perror("fork");
			return ;
		}
		if (pids[i] == 0)
		{
			if (cur->next)
				child_exec(shell, cur, prev_read, pipefd[1]);
			else
				child_exec(shell, cur, prev_read, STDOUT_FILENO);
		}
		close_fd_if_needed(prev_read);
		if (cur->next)
		{
			close(pipefd[1]);
			prev_read = pipefd[0];
		}
		cur = cur->next;
		i++;
	}
	close_fd_if_needed(prev_read);
	wait_all(shell, pids, count);
	free(pids);
}
