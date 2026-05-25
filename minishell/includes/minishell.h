/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasper <akasper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 17:26:02 by acasper           #+#    #+#             */
/*   Updated: 2026/05/25 17:31:22 by akasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/includes/libft.h"
# include "arena.h"
# include "lexer.h"
# include "parser.h"
# include <errno.h>
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_shell
{
	char						**env;
	int							last_status;
	int							running;
	int							should_exit;
	char						*input;
	t_token						*tokens;
	t_cmd						*cmds;
}								t_shell;

extern volatile sig_atomic_t	g_signal;

void							prompt_loop(t_shell *shell);
void							execute_command(char *input, char **envp);
char							**split_args(char *input);
void							free_args(char **args);

int								prepare_heredocs(t_cmd *cmds);

void							execute_pipeline(t_shell *shell, t_cmd *cmds);
void							execute_single_command(t_shell *shell,
									t_cmd *cmd);
void							clean_exit(t_shell *shell, int status);
int								save_stdio(int saved[2]);
void							restore_stdio(int saved[2]);
void							run_saved_builtin(t_shell *shell,
									t_cmd *cmd, int saved[2]);
void							wait_for_child(t_shell *shell, pid_t pid);
void							execute_multi_command(t_shell *shell,
									t_cmd *cmds);
int								create_pipe_if_needed(t_cmd *cmd,
									int pipefd[2]);
void							run_pipe_child(t_shell *shell, t_cmd *cmd,
									int prev_read, int pipefd[2]);
int								fork_one_pipe(t_shell *shell, t_cmd *cmd,
									int prev_read, int pipefd[2], pid_t *pid);
void							parent_close_pipe_fds(t_cmd *cmd,
									int *prev_read, int pipefd[2]);
int								apply_redirections(t_redir *redirs);
char							*get_env_value(char **envp, char *key);
char							*find_command_path(char *cmd, char **envp);
int								is_buildin(char *cmd);
int								execute_buildin(t_shell *shell, t_cmd *cmd);
void							close_fd_if_needed(int fd);
void							print_exec_error(char *cmd);
void							child_exec(t_shell *shell, t_cmd *cmd,
									int in_fd, int out_fd);

void							setup_signals(void);
void							setup_child_signals(void);

// buildins & env utils
int								ft_cd(char **args, t_shell *shell);
int								ft_env(t_shell *shell);
int								ft_export(char **args, t_shell *shell);
int								ft_unset(char **args, t_shell *shell);
int								ft_echo(char **args);
int								ft_exit(char **args, t_shell *shell);
int								ft_pwd(void);
int								update_env(char **env, char *key, char *value);
char							*get_env_value(char **env, char *key);
char							**cpy_env(char **env);
void							print_export(char **env);
void							add_to_env(t_shell *shell, char *name,
									char *value);
void							free_env(char **env);

#endif
