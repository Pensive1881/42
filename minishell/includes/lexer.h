/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrajni <rrajni@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 15:19:37 by rrajni            #+#    #+#             */
/*   Updated: 2026/05/21 15:46:23 by rrajni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include <stddef.h>
# include <stdlib.h>
# include "../libft/includes/libft.h"

typedef struct s_shell	t_shell;

typedef enum e_token_type
{
	TOKEN_WORD,
	TOKEN_PIPE,
	TOKEN_REDIRECT_IN,
	TOKEN_REDIRECT_OUT,
	TOKEN_HEREDOC,
	TOKEN_APPEND,
}	t_token_type;

typedef struct s_word
{
	char	*input;
	t_shell	*shell;
}	t_word;

typedef struct s_token
{
	t_token_type		type;
	char				*value;
	char				quote; // this thinginew
	struct s_token		*next;
}	t_token;

// lexer_token.c
t_token	*lex_oprator(char *input, int *i);
t_token	*lex_word(char	*input, int *i, t_shell *shell);
t_token	*lex_quoted(char *input, int *i);
t_token	*create_token(t_token_type type, char *value);
// lex.c
t_token	*lexer(char *input, t_shell *shell);
void	add_token(t_token **head, t_token **current, t_token *token);
void	white_sapaces( char *input, int	*i);
char	is_whitespace(char c);
char	is_operator(char c);
// lex.utils.c
void	free_tokens(t_token *head);
char	*expand_var(char *input, int *i, t_shell *shell);
// expansion/expand.c
t_token	expand_tokens(t_token *tokens, t_shell *shell); //new thingi

#endif
