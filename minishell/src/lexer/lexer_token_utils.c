/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_token_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrajni <rrajni@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 16:12:47 by rrajni            #+#    #+#             */
/*   Updated: 2026/05/21 14:17:59 by rrajni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "minishell.h"
#include "../../libft/includes/libft.h"

void	free_tokens(t_token *head)
{
	t_token	*current;
	t_token	*next;

	current = head;
	while (current)
	{
		next = current->next;
		free(current->value);
		free(current);
		current = next;
	}
}

void	add_token(t_token **head, t_token **current, t_token *token)
{
	if (!*head)
	{
		*head = token;
		*current = token;
	}
	else
	{
		(*current)->next = token;
		*current = token;
	}
}

char	*expand_var(char *input, int *i, t_shell *shell)
{
	char	*variable;
	char	*value;
	int		start;

	if (input[*i] == '$')
		(*i)++;
	if (input[*i] == '?')
	{
		(*i)++;
		return (ft_itoa(shell->last_status));
	}
	if (!input[*i] || (!ft_isalnum(input[*i]) && input[*i] != '_'))
		return (ft_strdup("$"));
	start = *i;
	while (ft_isalnum(input[*i]) || input[*i] == '_')
		(*i)++;
	variable = ft_substr(input, start, *i - start);
	value = get_env_value(shell->env, variable);
	free(variable);
	if (!value)
		return (ft_strdup(""));
	return (ft_strdup(value));
}

t_token	*lex_quoted(char *input, int *i)
{
	t_token	*token;
	char	quote;
	int		start;
	char	*value;

	quote = input[*i];
	(*i)++;
	start = *i;
	while (input[*i] && input[*i] != quote)
		(*i)++;
	if (input[*i] == quote)
	{
		value = ft_substr(input, start, *i - start);
		(*i)++;
	}
	else
		return (NULL);
	token = create_token(TOKEN_WORD, value);
	token->quote = quote; //the new thingi
	return (token);
}

t_token	*create_token(t_token_type type, char *value)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	token->type = type;
	token->value = value;
	token->quote = '\0'; //new thingi
	token->next = NULL;
	return (token);
}
