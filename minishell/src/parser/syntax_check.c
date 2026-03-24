#include "../../includes/parser.h"

static int	is_pipe_error(t_token *prev, t_token *cur)
{
	
}

static int	is_redir_error(t_token *cur)
{
	
}

int	validate_syntax(t_token *tokens)
{
	t_token *prev;
	t_token *cur;

	prev = NULL;
	cur = tokens;
	while (cur)
	{
		if (cur->type == TOKEN_PIPE)
		{
			if (is_pipe_error(prev, cur))
				return (0);
		}
		else if (is_redirection(cur->type))
		{
			if (is_pipe_error(cur))
				return (0);
		}
		prev = cur;
		cur = cur->next;
	}
	return (1);
}

