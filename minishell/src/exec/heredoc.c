#include "../../includes/minishell.h"

static int	write_heredoc_to_file(char *delimiter, char *filename)
{
	
}

static int	prepare_cmd_heredocs(t_cmd *cmd, int *index)
{
	t_redir	*redir;
	char	*tmp_name;
	char	*num;

	redir = cmd->redirs;
	while (redir)
	{
		if (redir->type == R_HEREDOC)
		{
			num = ft_itoa((*index)++);
			if (!num)
				return (0);
			tmp_name = ft_strjoin("/tmp/minishell_hd_", num);
			free(num);
			if (!tmp_name)
				return (0);
			if (!write_heredoc_to_file(redir->file, tmp_name))
			{
				free(tmp_name);
				return (0);
			}
			free(redir->file);
			redir->file = tmp_name;
			redir->type = R_IN;
		}
		redir = redir->next;
	}
	return (1);
}

int	prepare_heredocs(t_cmd *cmds)
{
	int	index;

	index = 0;
	while (cmds)
	{
		if (!prepare_cmd_heredocs(cmds, &index))
			return (0);
		cmds = cmds->next;
	}
	return (1);
}
