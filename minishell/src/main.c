/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 17:27:22 by acasper           #+#    #+#             */
/*   Updated: 2026/03/31 18:18:58 by rrajni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	//char	**env; this arry contains the cpy of env vars
	
	//env = cpy_env(envp);
	//prompt_loop(env);
	prompt_loop(envp); // this line will have to be deleted when using the lines above
	return (0);
}
