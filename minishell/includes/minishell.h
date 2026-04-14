/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 17:26:02 by acasper           #+#    #+#             */
/*   Updated: 2026/03/04 17:55:16 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

//# include "lexer.h"
# include "../libft/includes/libft.h" //being added to include libft 
# include "lexer.h"
# include "arena.h"
# include "parser.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <fcntl.h>
# include <errno.h>

typedef struct	s_shell
{
	char	**env;
	int	last_status;
	int	running;
}	t_shell;

extern volatile sig_atomic_t	g_signal;

void	prompt_loop(t_shell *shell);
void	execute_command(char *input, char **envp);
char	**split_args(char *input);
void	free_args(char **args);

void	execute_pipeline(t_shell *shell, t_cmd *cmds);
void	execute_single_command(t_shell *shell, t_cmd *cmd);
void	execute_multi_command(t_shell *shell, t_cmd *cmds);
int	apply_redirections(t_redir *redirs);
char	*get_env_value(char **envp, char *key);
char	*find_command_path(char *cmd, char **envp);
int	is_buildin(char *cmd);
int	execute_buildin(t_shell *shell, t_cmd *cmd);
void	close_fd_if_needed(int fd);
void	print_exec_error(char *cmd);
void	child_exec(t_shell *shell, t_cmd *cmd, int in_fd, int out_fd);

void	setup_signals(void);
void	setup_child_signals(void);

char	**cpy_env(char **env);
void	free_env(char **env);

#endif
