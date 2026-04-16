/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sync.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 19:06:43 by acasper           #+#    #+#             */
/*   Updated: 2026/04/16 19:06:45 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

int	get_stop(t_table *table)
{
	int	value;

	pthread_mutex_lock(&table->stop_mutex);
	value = table->simulation_stop;
	pthread_mutex_unlock(&table->stop_mutex);
	return (value);
}

void	set_stop(t_table *table, int value)
{
	pthread_mutex_lock(&table->stop_mutex);
	table->simulation_stop = value;
	pthread_mutex_unlock(&table->stop_mutex);
}

void	print_state(t_philo *philo, char *msg)
{
	pthread_mutex_lock(&philo->table->print_mutex);
	if (!get_stop(philo->table))
	{
		printf("%ld %d %s\n",
			timestamp_ms(philo->table->start_time),
			philo->id, msg);
	}
	pthread_mutex_unlock(&philo->table->print_mutex);
}

void	precise_sleep(long time, t_table *table)
{
	long	start;

	start = get_time();
	while (!get_stop(table))
	{
		if (get_time() - start >= time)
			break ;
		usleep(500);
	}
}

