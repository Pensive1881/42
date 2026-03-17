#include "lexer.h"

void	white_sapaces( char *input, int	*i)
{
	while (input && input[*i] == ' ' || input[*i] == '\t'))
		(*i)++;
}

char	is_whitespace(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13) || c == '\n')
}

char	is_operator(char c)
{
	return (c == '|' || c == '<' || c == '>')
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

t_token	*lexer(char *input)
{
	t_token	*head;
	t_token	*current;
	t_token *token;
	int	i;
	
	if (!input || input[0] == '\0')
		return (NULL);
	i = 0;
	head = NULL;
	current = NULL;
	while (input[i])
	{
		white_sapaces(input, &i);
		if (is_operator(input[i]))
			token = lex_operator(input, &i);
		else if (input[i] == '"' || input[i] == '\'')
			token = lex_quoted(input, &i);
		else
		{
			token = lex_word(input, &i);
			add_token(&head, &current, token);
		}
	}
	return (head);
}
