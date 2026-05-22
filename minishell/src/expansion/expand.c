/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrajni <rrajni@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 16:04:35 by rrajni            #+#    #+#             */
/*   Updated: 2026/05/20 16:06:45 by rrajni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../includes/lexer.h"

static	char	*handler(char *str, int *i, char *result)
{
	char	*old_result;
	char	*temp;
	int		start;

	start = *i;
	while (str[*i] && str[*i] != '$')
		(*i)++;
	temp = ft_substr(str, start, *i - start);
	old_result = result;
	result = ft_strjoin(result, temp);
	free(old_result);
	free(temp);
	return (result);
}
static	char	*char_handler(char *str, int *i, t_shell *shell, char *result)
{
	char	*old_value;
	char	*value;
	if (str[*i] == '$')
	{
		value = expand_var(str, i, shell);
		old_value = value;
		result = ft_strjoin(result, value);
		free(old_value);
	}
	else
		result = handler(str, i, result);
	return (result);
}	
char	*expend_value(char *str, t_shell *shell)
{
	int		i;
	char	*result;

	i = 0;
	result = ft_strdup("");
	while (str[i])
	{
		result = char_handler(str, &i, shell, result);
	}
	return (result);
}

t_token	expand_tokens(t_token *tokens, t_shell *shell)
{
	t_token	*current;
	char	*old;

	current = tokens;
	while (current)
	{
		if (current->type == TOKEN_WORD && current->quote != '\'')
		{
			old = current->value;
			current->value = expend_value(current->value, shell);
			free(old);
		}
		current = current->next;
	}
	return (*tokens);
}
