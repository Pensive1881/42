/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 19:06:12 by acasper           #+#    #+#             */
/*   Updated: 2026/04/16 19:06:14 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

int	init_philos(t_table *table)
{
	int	i;

	table->philos = malloc(sizeof(t_philo) * table->number_of_philosophers);
	if (!table->philos)
		return (1);
	i = 0;
	while (i < table->number_of_philosophers)
	{
		table->philos[i].id = i + 1;
		table->philos[i].meals_eaten = 0;
		table->philos[i].last_meal_time = table->start_time;
		table->philos[i].left_fork = &table->forks[i];
		table->philos[i].right_fork = &table->forks[(i + 1)
			% table->number_of_philosophers];
		table->philos[i].table = table;
		i++;
	}
	return (0);
}

int	start_threads(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->number_of_philosophers)
	{
		if (pthread_create(&table->philos[i].thread, NULL, routine,
				&table->philos[i]) != 0)
			return (1);
		i++;
	}
	return (0);
}

void	join_threads(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->number_of_philosophers)
	{
		pthread_join(table->philos[i].thread, NULL);
		i++;
	}
}

void    cleanup(t_table *table)
{
        int     i;

        if (table->forks)
        {
                i = 0;
                while (i < table->number_of_philosophers)
                {
                        pthread_mutex_destroy(&table->forks[i]);
                        i++;
                }
                free(table->forks);
        }
        pthread_mutex_destroy(&table->print_mutex);
        pthread_mutex_destroy(&table->stop_mutex);
        pthread_mutex_destroy(&table->meal_mutex);
        if (table->philos)
                free(table->philos);
}
