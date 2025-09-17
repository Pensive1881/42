/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 19:00:30 by acasper           #+#    #+#             */
/*   Updated: 2025/09/17 18:00:55 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

static void	sig_handler(int signo, sigingo_t *info, void *content)
{
	
}

int	main(void)
{
	struct sigaction	sa;

	while (1)
		pause();
}

