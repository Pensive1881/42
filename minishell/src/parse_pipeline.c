#include "../includes/parser.h"

t_cmd	*parse_pipeline(t_token **cur)
{
	t_cmd	*head;
	t_cmd	*last;
	t_cmd	*new_cmd;

	head = parse_command(cur);
	if (!head)
		return (NULL);
	last = head;
	while (*cur && (*cur)->type == TOKEN_PIPE)
	{
		*cur = (*cur)->next;
		new_cmd = parse_command(cur);
		if (!new_cmd)
		{
			free_cmds(head);
			return (NULL);
		}
		last->next = new_cmd;
		last = new_cmd;
	}
	return (head);
}
