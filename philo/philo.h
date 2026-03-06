/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 15:21:39 by acasper           #+#    #+#             */
/*   Updated: 2026/03/04 16:24:48 by acasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_data t_data;
typedef struct s_philos t_philos;

typedef struct  s_philos
{
        int     *id;
        int     meals_eaten;
        long    last_meal_time;

	pthread_t	thread;

	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;

        t_data  *data;
}       t_philos;

typedef struct	s_data
{
	int	number_of_philosophers;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	int	must_eat_count;

	long	start_time;
	int	simulation_stop;

	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
}	t_data;

long	get_time(void);
void	precise_sleep(long time, t_data *data);
void	print_state(t_philos *philo, char *msg);

#endif
