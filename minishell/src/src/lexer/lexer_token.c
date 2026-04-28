#include "lexer.h"
#include "../../libft/includes/libft.h"

t_token	*lex_oprator(char *input, int *i)
{
	t_token	*token = NULL;

	if (input[*i] == '|')
	{
		token = create_token(TOKEN_PIPE, ft_strdup("|"));
		*i += 1;
	}
	else if (input[*i] == '<')
	{
		if (input[*i + 1] == '<')
		{
			token = create_token(TOKEN_HEREDOC, ft_strdup("<<"));
			*i += 2;
		}
		else
		{
			token = create_token(TOKEN_REDIRECT_IN, ft_strdup("<"));
			*i += 1;
		}
	}
	else if (input[*i] == '>')
	{
		if (input[*i + 1] == '>')
		{
			token = create_token(TOKEN_APPEND, ft_strdup(">>"));
			*i += 2;
		}
		else
		{
			token = create_token(TOKEN_REDIRECT_OUT, ft_strdup(">"));
			*i += 1;
		}
	}
	return (token);
}

t_token	*lex_word(char	*input, int *i)
{
	t_token	*token;
	int	start;
	char	*value;

	start = *i;
	value = ft_strdup("");
	while (input[*i] != '\0' && !is_operator(input[*i]) 
				&& !is_whitespace(input[*i]) 
				&& input[*i] != '"' && input[*i] != '\'')
	{
		if (input[*i] == '$')
		{
			// append the part before $
			char *before = ft_substr(input, start, *i - start);
			char *temp = ft_strjoin(value, before);
			free(value);
			free(before);
			value = temp;
			// expand the variable
			char *expanded = expand_var(input, i);
			if (expanded)
			{
				temp = ft_strjoin(value, expanded);
				free(value);
				value = temp;
			}
			start = *i; // update start after expansion
		}
		else
			(*i)++;
	}
	// append the remaining part
	char *rest = ft_substr(input, start, *i - start);
	char *final_value = ft_strjoin(value, rest);
	free(value);
	free(rest);
	token = create_token(TOKEN_WORD, final_value);
	token->quote = 0;
	return (token);
}

t_token	*lex_quoted(char *input, int *i)
{
	t_token *token;
	char	quote;
	int	start;
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
		return (NULL); // unclosed quote
	token = create_token(TOKEN_WORD, value);
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
	token->next = NULL;
	return (token);
}
