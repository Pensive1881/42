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

static int	take_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->right_fork);
		if (get_stop(philo->table))
			return (pthread_mutex_unlock(philo->right_fork), 1);
		print_state(philo, "has taken a fork");
		pthread_mutex_lock(philo->left_fork);
		if (get_stop(philo->table))
		{
			pthread_mutex_unlock(philo->left_fork);
			pthread_mutex_unlock(philo->right_fork);
			return (1);
		}
		print_state(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(philo->left_fork);
		if (get_stop(philo->table))
			return (pthread_mutex_unlock(philo->left_fork), 1);
		print_state(philo, "has taken a fork");
		pthread_mutex_lock(philo->right_fork);
		if (get_stop(philo->table))
		{
			pthread_mutex_unlock(philo->right_fork);
			pthread_mutex_unlock(philo->left_fork);
			return (1);
		}
		print_state(philo, "has taken a fork");
	}
	return (0);
}

static void	eat_sleep_think(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->meal_mutex);
	philo->last_meal_time = get_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->table->meal_mutex);
	print_state(philo, "is eating");
	precise_sleep(philo->table->time_to_eat, philo->table);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	if (get_stop(philo->table))
		return ;
	print_state(philo, "is sleeping");
	precise_sleep(philo->table->time_to_sleep, philo->table);
	if (get_stop(philo->table))
		return ;
	smart_think(philo);
}

static void	one_philo_case(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	print_state(philo, "has taken a fork");
	precise_sleep(philo->table->time_to_die, philo->table);
	pthread_mutex_unlock(philo->left_fork);
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
		if (take_forks(philo))
			break ;
		eat_sleep_think(philo);
	}
	return (NULL);
}
