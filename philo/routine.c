/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 17:37:10 by acasper           #+#    #+#             */
/*   Updated: 2026/04/14 17:37:13 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

static void	take_forks(t_philo *philo)
{
	if (philo->id & 2 == 0)
	{
		pthread_mutex_lock(philo->right_fork);
		print_state();
		pthread_mutex();
		print_state();
	}
	else
	{
		pthread_mutex();
		print_state();
		pthread_mutex();
		print_state();
	}
}

static void	eat_sleep_think(t_philo *philo)
{
	
}

static void	one_philo_case(t_philo *philo)
{
	pthread_mutex_lock();
	print_state();
	precise_sleep();
	pthread_mutex_unlock();
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->table->number_of_philosophers == 1)
	{
		one_philo_case(philo);
		return (NULL);
	}
	if (philo->id % 2 == 0)
		usleep(1000);
	while (!get_stop(philo->table))
	{
		take_forks(philo);
		eat_sleep_think(philo);
	}
	return (NULL);
}
