#include "../../includes/parser.h"

t_cmd	*parse_tokens(t_token *tokens)
{
	t_token	*cur;

	if (!tokens)
		return (NULL);
	cur = tokens;
	return (parse_pipeline(&cur));
}
