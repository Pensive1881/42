/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrajni <rrajni@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 16:14:21 by rrajni            #+#    #+#             */
/*   Updated: 2026/05/21 18:02:58 by rrajni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/includes/libft.h"
#include "lexer.h"

static t_token	*weirdies(char *input, int *i)
{
	if (input[*i] == '<')
	{
		if (input[*i + 1] == '<')
		{
			*i += 2;
			return (create_token(TOKEN_HEREDOC, ft_strdup("<<")));
		}
		*i += 1;
		return (create_token(TOKEN_REDIRECT_IN, ft_strdup("<")));
	}
	else
	{
		if (input[*i + 1] == '>')
		{
			*i += 2;
			return (create_token(TOKEN_APPEND, ft_strdup(">>")));
		}
		*i += 1;
		return (create_token(TOKEN_REDIRECT_OUT, ft_strdup(">")));
	}
}

t_token	*lex_oprator(char *input, int *i)
{
	t_token	*token;

	token = NULL;
	if (input[*i] == '|')
	{
		token = create_token(TOKEN_PIPE, ft_strdup("|"));
		*i += 1;
	}
	else
		token = weirdies(input, i);
	return (token);
}

static char	*doller(t_word *w, int *i, char *value, int *start)
{
	char	*rest;
	char	*temp;
	char	*expanded;

	if (*i > *start)
	{
		rest = ft_substr(w->input, *start, *i - *start);
		temp = ft_strjoin(value, rest);
		free(value);
		free(rest);
		value = temp;
	}
	expanded = expand_var(w->input, i, w->shell);
	temp = ft_strjoin(value, expanded);
	free(value);
	free(expanded);
	*start = *i;
	return (temp);
}

static char	*full_word(char *input, int *i, int start, char *value)
{
	char	*rest;
	char	*final_value;

	if (*i > start)
	{
		rest = ft_substr(input, start, *i - start);
		final_value = ft_strjoin(value, rest);
		free(value);
		free(rest);
		return (final_value);
	}
	return (value);
}

t_token	*lex_word(char *input, int *i, t_shell *shell)
{
	t_word	w;
	int		start;
	char	*value;

	w.input = input;
	w.shell = shell;
	start = *i;
	value = ft_strdup("");
	while (input[*i] && !is_operator(input[*i]) && !is_whitespace(input[*i])
		&& input[*i] != '"' && input[*i] != '\'')
	{
		if (input[*i] == '$')
			value = doller(&w, i, value, &start);
		else
			(*i)++;
	}
	return (create_token(TOKEN_WORD, full_word(input, i, start, value)));
}