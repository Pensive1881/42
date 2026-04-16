/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 17:35:50 by acasper           #+#    #+#             */
/*   Updated: 2026/04/16 18:05:37 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

static int	init_forks(t_table *table)
{
	int	i;

	table->forks = malloc(sizeof(pthread_mutex_t)
			* table->number_of_philosophers);
	if (!table->forks)
		return (1);
	i = 0;
	while (i < table->number_of_philosophers)
	{
		if (pthread_mutex_init(&table->forks[i], NULL) != 0)
			return (1);
		i++;
	}
	return (0);
}

int	parse_args(t_table *table, int argc, char **argv)
{
	if (argc != 5 && argc != 6)
	{
		printf("Error\n");
		return (1);
	}
	table->number_of_philosophers = ft_atoi_positive(argv[1]);
	table->time_to_die = ft_atoi_positive(argv[2]);
	table->time_to_eat = ft_atoi_positive(argv[3]);
	table->time_to_sleep = ft_atoi_positive(argv[4]);
	table->must_eat_count = -1;
	if (argc == 6)
		table->must_eat_count = ft_atoi_positive(argv[5]);
	if (table->number_of_philosophers <= 0 || table->time_to_die <= 0
		|| table->time_to_eat <= 0 || table->time_to_sleep <= 0 || (argc == 6
			&& table->must_eat_count <= 0))
		return (1);
	return (0);
}

int	init_table(t_table *table)
{
	table->simulation_stop = 0;
	table->start_time = get_time();
	if (pthread_mutex_init(&table->print_mutex, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&table->stop_mutex, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&table->meal_mutex, NULL) != 0)
		return (1);
	if (init_forks(table))
		return (1);
	return (0);
}