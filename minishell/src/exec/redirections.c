/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 21:01:01 by acasper           #+#    #+#             */
/*   Updated: 2026/03/31 21:01:04 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minishell.h"

static int	open_redir_file(t_redir *redir)
{
	int	fd;

	fd = -1;
	if (redir->type == R_IN)
		fd = open(redir->file, O_RDONLY);
	else if (redir->type == R_OUT)
		fd = open(redir->file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (redir->type == R_APPEND)
		fd = open(redir->file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else if (redir->type == R_HEREDOC)
	{
		int pipefd[2];
		char	*line;

		if (pipe(pipefd) < 0)
			return (perror("pipe"), -1);

		while (1)
		{
			line = readlin("> ");
			if (!line)
				break;
			if (ft_strcmp(line, redir->file) == 0)
			{
				free(line);
				break;
			}
			write(pipefd[1], line, ft_strlen(line));
			write(pipefd[1], "\n", 1);
			free(line);
		}
		close(pipefd[1]);
		return (pipefd[0]);
	}
	if (fd < 0)
		perror(redir->file);
	return (fd);
}

int	apply_redirections(t_redir *redirs)
{
	int	fd;

	while (redirs)
	{
		fd = open_redir_file(redirs);
		if (fd < 0)
			return (0);
		if (redirs->type == R_IN || redirs->type == R_HEREDOC)
		{
			if (dup2(fd, STDIN_FILENO) < 0)
				return (close(fd), perror("dup2"), 0);
		}
		else
		{
			if (dup2(fd, STDOUT_FILENO) < 0)
				return (close(fd), perror("dup2"), 0);
		}
		close(fd);
		redirs = redirs->next;
	}
	return (1);
}
