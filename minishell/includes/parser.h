#ifndef PARSER_H
# define PARSER_H

#include <stdlib.h>
#include "lexer.h"
#include "libft.h"

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
	char	*file;
	struct s_redir	*next;
}	t_redir;

typedef struct s_cmd
{
	char	**argv;
	int	argc;
	t_redir	*redirs;
	struct s_cmd	*next;
}	t_cmd;

// parse_redirection.c


// free_parser.c


// cmd_utils.c


// more....



#endif 
