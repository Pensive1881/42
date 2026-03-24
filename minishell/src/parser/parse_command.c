#include "../../includes/parser.h"

t_cmd	*parse_command(t_token **cur)
{
	t_cmd	*cmd;
	t_redir	*redir;
	
	if (!cur || !*cur)
		return (NULL);
	cmd = init_cmd();
	if (!cmd)
		return (NULL);
	while (*cur && (*cur)->type != TOKEN_PIPE)
	{
		if ((*cur)->type == TOKEN_WORD)
		{
			if (!add_word_to_cmd(cmd, (*cur)->value))
				return (free_cmd_and_null(cmd));
			*cur = (*cur)->next;
		}
		else if (is_redirection((*cur)->type))
		{
			redir = parse_redirection(cur);
			if (!redir || !add_redir_to_cmd(cmd, redir))
				return (free_cmd_and_null(cmd));
		}
		else
			return (free_cmd_and_null(cmd));
	}

	return (cmd);
}
