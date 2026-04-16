/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 15:21:05 by acasper           #+#    #+#             */
/*   Updated: 2026/04/16 17:19:06 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

int	main(int argc, char **argv)
{
	t_table	table;

	table.forks = NULL;
	table.philos = NULL;
	if (parse_args(&table, argc, argv))
		return (1);
	if (init_table(&table))
	{
		cleanup(&table);
		return (1);
	}
	if (init_philos(&table))
	{
		cleanup(&table);
		return (1);
	}
	if (start_threads(&table))
	{
		cleanup(&table);
		return (1);
	}
	monitor_simulation(&table);
	join_threads(&table);
	cleanup(&table);
	return (0);
}
