#ifndef LEXER_H
# define LEXER_H

typedef	enum e_token_type
{
	TOKEN_WORD;
	TOKEN_PIPE;
	TOKEN_REDIRECT_IN;
	TOKEN_REDIRECT_OUT;
	TOKEN_HEREDOC;
	TOKEN_APPEND;
}	t_token_type;

typedef	struct	s_token
{
	t_token_type	type;
	char		*value;
	struct	s_token	*next;
}	t_token;

// lexer_token.c
t_token	*lex_oprator(char *input, int *i);
t_token	*lex_word(char	*input, int *i);
t_token	*lex_quoted(char *input, int *i);
t_token	*create_token(t_token_type type, char *value);
// lex.c
t_token	*lexer(char *input);
void	add_token(t_token **head, t_token **current, t_token *token);
void	white_sapaces( char *input, int	*i);
char	is_whitespace(char c);
char	is_operator(char c);

# endif
