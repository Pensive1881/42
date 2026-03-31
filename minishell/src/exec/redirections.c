#include "../../inclues/minishell.h"

static int	open_redir_file(t_redir *redir)
{
	int	fd;

	fd = -1;
	
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
		if ()
		{
			
		}
		else
		{
			
		}
		close(fd);
		redirs = redirs->next;
	}
	return (1);
}
