#include "lexer.h"
#include "libft.h"

t_token	*lex_oprator(char *input, int *i)
{
	t_token	*token;

	if (input[*i] == '>' && input[*i + 1] == '>')
	{
		token = create_token(TOKEN_APPEND, ">>");
		*i += 2;	
	}
	else if (input[*i] == '>')
	{
		token = create_token(TOKEN_REDIR_OUT, '>');
		*i++;
	}
	if (input[*i] == '<' && input [*i + 1] == '<')
	{
		token = create_token(TOKEN_HEREDOC, "<<");
		*i += 2;	
	} 
	else if (input[*i])
	{
		token = create_token(TOKEN_REDIR_IN, '<');
		*i++;
	}
	else if (input[*i] == '|')
	{
		token = create_token(TOKEN_PIPE, '|');
		*i++;
	}
	return (token);
}

t_token	*lex_word(char	*input, int *i)
{
	t_token	*token;
	int	start;
	char	*value;

	if (input[*i])
		start = *i;
	while (input[*i] != '\0' && !is_oprator(input[*i]) 
				&& !is_whitespace(input[*i]) 
				&& input[*i] != '"' && input[*i] != '\'')
		*i++;
	value = ft_substr(input, start, *i - start);
	token = create_token(TOKEN_WORD, value);
	return (token);
}

t_token	*lex_quoted(char *input, int *i)
{
	t_token *token;
	char	quote;
	int	start;
	char	*value;

	quote = input[*i];
	*i++;
	start = *i;
	while (input[*i] && input[*i] != quote)
	{
		if (input[i] == quote)
			value = ft_substr(input, start, *i - start);
		*i++;
	}
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
