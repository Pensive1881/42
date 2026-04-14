/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 18:10:18 by acasper           #+#    #+#             */
/*   Updated: 2026/03/03 18:10:19 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

static int	all_ate_enough(t_table *table)
{
	int	i;
	int	done;

	if (table->must_eat_count == -1)
		return (0);
	i = 0;
	done = 1;
	pthread_mutex_lock(&table->meal_mutex);
	while (i < table->number_of_philosophers)
	{
		if (table->philos[i].meals_eaten < table->must_eat_count)
			done = 0;
		i++;
	}
	pthread_mutex_unlock(&table->meal_mutex);
	return (done);
}

int	monitor_simulation(t_table *table)
{
	int	i;
	long	now;

	while (!get_stop(table))
	{
		i = 0;
		while (i < table->number_of_philosophers)
		{
			pthread_mutex_lock(&table->meal_mutex);
			now = get_time();
			if (now - table->philos[i].last_meal_time > table->time_to_die)
			{
				pthread_mutex_unlock(&table->meal_mutex);
				pthread_mutex_lock(&table->print_mutex);
				printf("%ld %d died\n",
					timestamp_ms(table->start_time),
					table->philos[i].id);
				pthread_mutex_unlock(&table->print_mutex);
				set_setop(table, 1);
				return (1);
			}
			pthread_mutex_unlock(&table->meal_mutex);
			i++;
		}
		if (all_ate_enough(table))
		{
			set_stop(table, 1);
			return (0);
		}
		usleep(1000);
	}
	return (0);
}
