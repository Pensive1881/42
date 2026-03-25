/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 17:40:07 by acasper           #+#    #+#             */
/*   Updated: 2026/03/25 17:40:08 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <stdlib.h>
# include "lexer.h"
# include "libft.h"
/*
# include "arena.h"
*/

typedef enum	e_redir_type
{
	R_IN,
	R_OUT,
	R_HEREDOC,
	R_APPEND
}	t_redir_type;

typedef struct	s_redir
{
	t_redir_type	type;
	char		*file;
	struct s_redir	*next;
}	t_redir;

typedef struct s_cmd
{
	char		**argv;
	int		argc;
	t_redir		*redirs;
	struct s_cmd	*next;
}	t_cmd;

// parse_redirection.c
int	is_redirection(t_token_type type);
t_redir_type	token_to_redir_type(t_token_type type);
t_redir	*new_redir(t_redir_type type, char *file);
t_redir	*parse_redirection(t_token **cur);

// free_parser.c
void	free_redirs(t_redir *redirs);
void	free_cmds(t_cmd *cmds);

// cmd_utils.c
t_cmd	*init_cmd(void);
int	add_word_to_cmd(t_cmd *cmd, char *word);
int	add_redir_to_cmd(t_cmd *cmd, t_redir *redir);
t_cmd	*free_cmd_and_null(t_cmd *cmd);
/*
t_cmd	*init_cmd(t_arena *arena);
int	add_word_to_cmd(t_cmd *cmd, char *word, t_arena *arena);
*/

// more....
t_cmd	*parse_command(t_token **cur);
t_cmd	*parse_pipeline(t_token **cur);
t_cmd	*parse_tokens(t_token *tokens);
int	validate_syntax(t_token *tokens);
/*
t_cmd	*parse_command(t_token **cur, t_arena *arena);
t_cmd	*parse_pipeline(t_token **cur, t_arena *arena);
t_cmd	*parse_tokens(t_token *tokens, t_arena *arena);
*/

#endif 
