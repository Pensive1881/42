/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redirection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 17:44:24 by acasper           #+#    #+#             */
/*   Updated: 2026/03/25 17:44:25 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

	redir = malloc(sizeof(t_redir));
	if (!redir)
		return (NULL);
	redir->type = type;
	redir->file = ft_strdup(file);
	if (!redir->file)
	{
		free(redir);
		return (NULL);
	}
	redir->next = NULL;
	return (redir);
}

t_redir	*parse_redirection(t_token **cur)
{
	t_redir_type	type;
	t_redir	*redir;

	if (!cur || !*cur || !is_redirection((*cur)->type))
		return (NULL);
	type = token_to_redir_type((*cur)->type);
	*cur = (*cur)->next;
	if (!*cur || (*cur)->type != TOKEN_WORD)
		return (NULL);
	redir = new_redir(type, (*cur)->value);
	if (!redir)
		return (NULL);
	*cur = (*cur)->next;
	return (redir);
}
