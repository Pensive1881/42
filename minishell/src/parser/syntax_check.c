/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 17:44:33 by acasper           #+#    #+#             */
/*   Updated: 2026/05/12 16:41:34 by rrajni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

static int	is_pipe_error(t_token *prev, t_token *cur)
{
	if (!prev)
		return (1);
	if (!cur->next)
		return (1);
	if (prev->type == TOKEN_PIPE)
		return (1);
	if (cur->next->type == TOKEN_PIPE)
		return (1);
	return (0);
}

static int	is_redir_error(t_token *cur)
{
	if (!cur->next)
		return (1);
	if (cur->next->type != TOKEN_WORD)
		return (1);
	return (0);
}

int	validate_syntax(t_token *tokens)
{
	t_token	*prev;
	t_token	*cur;

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
			if (is_redir_error(cur))
				return (0);
		}
		prev = cur;
		cur = cur->next;
	}
	return (1);
}
