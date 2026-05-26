/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasper <akasper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 17:44:02 by acasper           #+#    #+#             */
/*   Updated: 2026/05/25 18:57:18 by akasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

static int	handle_word(t_cmd *cmd, t_token **cur)
{
	if (!add_word_to_cmd(cmd, (*cur)->value))
		return (0);
	*cur = (*cur)->next;
	return (1);
}

static int	handle_redirection(t_cmd *cmd, t_token **cur)
{
	t_redir	*redir;

	redir = parse_redirection(cur);
	if (!redir || !add_redir_to_cmd(cmd, redir))
		return (0);
	return (1);
}

t_cmd	*parse_command(t_token **cur)
{
	t_cmd	*cmd;

	if (!cur || !*cur)
		return (NULL);
	cmd = init_cmd();
	if (!cmd)
		return (NULL);
	while (*cur && (*cur)->type != TOKEN_PIPE)
	{
		if ((*cur)->type == TOKEN_WORD)
		{
			if (!handle_word(cmd, cur))
				return (free_cmd_and_null(cmd));
		}
		else if (is_redirection((*cur)->type))
		{
			if (!handle_redirection(cmd, cur))
				return (free_cmd_and_null(cmd));
		}
		else
			return (free_cmd_and_null(cmd));
	}
	return (cmd);
}
