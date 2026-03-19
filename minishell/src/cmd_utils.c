#include "../src/parser.h"

t_cmd	*init_cmd(void)
{
	t_cmd	*cmd;

	cmd = malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	cmd->argv = malloc(sizeof(char *));
	if (!cmd->argv)
	{
		free(cmd);
		return (NULL);
	}
	cmd->argv[0] = NULL;
	cmd->argc = 0;
	cmd->redirs = NULL;
	cmd->next = NULL;

	return (cmd);
}

static int	copy_old_args(char **new_argv, char **old_argv, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		new_argv[i] = old_argv[i];
		i++;
	}
	return (1);
}

int	add_word_to_cmd(t_cmd *cmd, char *word)
{
	
}

int	add_redir_to_cmd(t_cmd *cmd, t_redir *redir)
{
	
}

t_cmd	*free_cmd_and_null(t_cmd *cmd)
{
	free_cmds(cmds);
	return (NULL);
}
