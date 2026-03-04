/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 17:27:22 by acasper           #+#    #+#             */
/*   Updated: 2026/03/04 17:30:34 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <minishell.h>

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	prompt_loop(envp);
	return (0);
}

