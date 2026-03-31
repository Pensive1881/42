#include "../../inclues/minishell.h"

static int	open_redir_file(t_redir *redir)
{
	int	fd;

	fd = -1;
	if (redir->type == RE_IN)
		fd = open(redir->file, O_RDONLY);
	else if (redir->type == R_OUT)
		fd = open(redir->file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (redir->type == R_APPEND)
		fd = open(redir->file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else if (redir->type == R_HEREDOC)
	{
		ft_putendl_fd("heredoc not implemented yet", 2);
		return (-1);
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
		if (redirs->type == RE_IN || redirs->type == R_HEREDOC)
		{
			if (dup2(fd, STDIN_FILEO) < 0)
				return (close(fd), perror("dup2"), 0);
		}
		else
		{
			if (dup2(fd, STDOUT_FILEO) < 0)
				return (close(fd), perror("dup2"), 0);
		}
		close(fd);
		redirs = redirs->next;
	}
	return (1);
}
