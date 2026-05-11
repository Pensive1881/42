/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 17:36:30 by acasper           #+#    #+#             */
/*   Updated: 2026/04/16 19:29:31 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

long	timestamp_ms(long start_time)
{
	return (get_time() - start_time);
}

int	ft_atoi_positive(const char *str)
{
	long	result;
	int		i;

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

void	smart_think(t_philo *philo)
{
	print_state(philo, "is thinking");
	if (philo->table->number_of_philosophers % 2 != 0)
		precise_sleep(philo->table->time_to_eat, philo->table);
}

void	one_philo_case(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	print_state(philo, "has taken a fork");
	precise_sleep(philo->table->time_to_die, philo->table);
	pthread_mutex_unlock(philo->left_fork);
}
