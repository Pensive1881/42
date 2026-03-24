#include "../../includes/parser.h"

int	is_redirection(t_token_type type)
{
	return (type == TOKEN_REDIRECT_IN
		|| type == TOKEN_REDIRECT_OUT
		|| type == TOKEN_HEREDOC
		|| type == TOKEN_APPEND);
}

t_redir_type	token_to_redir_type(t_token_type type)
{
	if (type == TOKEN_REDIRECT_IN)
		return (R_IN);
	if (type == TOKEN_REDIRECT_OUT)
		return (R_OUT);
	if (type == TOKEN_HEREDOC)
		return (R_HEREDOC);
	return (R_APPEND);
}

t_redir *new_redir(t_redir_type type, char *file)
{
	t_redir	*redir;

	redir = malloc(siaeof(t_redir));
	
}

t_redir	*parse_redirection(t_token **cur)
{
	
}
