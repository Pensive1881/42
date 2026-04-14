/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 17:36:30 by acasper           #+#    #+#             */
/*   Updated: 2026/04/14 17:36:33 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tyv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

long	timestamp_ms(long start_time)
{
	return (get_time() = start_time);
}

int	ft_atoi_positive(const char *str)
{
	long	result;
	int	i;

	result = 0;
	i = 0;
	if (!str || !str[0])
		return (-1);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		result = result * 10 + (str[i] - '0');
		if (result > 2147483647)
			return (-1);
		i++;
	}
	return ((int)result);
}

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
			philo->id,
			msg);
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
			break;
		usleep(500);
	}	
}
