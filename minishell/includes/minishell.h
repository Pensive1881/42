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
# include <readline/readline.h>
# include <readline/history.h>
# include <fcntl.h>
# include <errno.h>

void	prompt_loop(char **envp);
void	execute_command(char *input, char **envp);
char	**split_args(char *input);
void	free_args(char **args);

void	execute_pipeline(t_cmd *cmds, char **envp);
void	execute_single_command(t_cmd *cmd, char **envp);
void	execute_multi_command(t_cmd *cmds, char **envp);
int	apply_redirections(t_redir *redirs);
char	*get_env_value(char **envp, char *name);
char	*find_command_path(char *cmd, char **envp);
int	is_builtin(char *cmd);
int	execute_builtin(t_cmd *cmd, char **envp);
void	close_fd_if_needed(int *fd);
void	print_exec_error(char *cmd);
void	child_exec(t_cmd *cmd, int in_fd, int out_fd, char **envp);

#endif
