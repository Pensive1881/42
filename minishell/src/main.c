/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 17:27:22 by acasper           #+#    #+#             */
/*   Updated: 2026/05/12 16:29:31 by rrajni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/minishell.h"

void	free_env(char **env)
{
	int	i;

	if (!env)
		return ;
	i = 0;
	while (env[i])
	{
		free(env[i]);
		i++;
	}
	free(env);
}

/*just incase if we need any of the following
//char  **env; this arry contains the cpy of env vars

        //env = cpy_env(envp);
        //prompt_loop(env);*/

int	main(int argc, char **argv, char **envp)
{
	t_shell	shell;

	(void)argc;
	(void)argv;
	shell.env = cpy_env(envp);
	if (!shell.env)
		return (1);
	shell.last_status = 0;
	shell.running = 1;
	setup_signals();
	prompt_loop(&shell);
	free_env(shell.env);
	return (0);
}
