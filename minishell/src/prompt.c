/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 17:27:45 by acasper           #+#    #+#             */
/*   Updated: 2026/03/04 17:51:11 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	prompt_loop(char **envp)
{
	char	*input;

	while (1)
	{
		input = readline("minishell$ ");
		if (!input)
			break;

		if (*input)
			add_history(input);

		execute_command(input, envp);
		free(input);
	}
}

