#include "../../includes/parser.h"

void	free_redirs(t_redir *redirs)
{
	t_redir	*tmp;

	while (redirs)
	{
		tmp = redirs->next;
		free(redirs->file);
		free(redirs);
		redirs = tmp;
	}
}

void	free_cmds(t_cmd *cmds)
{
	t_cmd	*tmp;
	int	i;

	while (cmds)
	{
		tmp = cmds->next;
		if (cmds->argv)
		{
			i = 0;
			while (cmds->argv[i])
			{
				free(cmds->argv[i]);
				i++;
			}
			free(cmds->argv);
		}
		free_redirs(cmds->redirs);
		free(cmds);
		cmds = tmp;
	}
}

