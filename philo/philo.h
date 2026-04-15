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

typedef struct s_table t_table;
typedef struct s_philo t_philo;

typedef struct  s_philo
{
        int     id;
        int     meals_eaten;
        long    last_meal_time;
	pthread_t	thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
        t_table	*table;
}       t_philo;

typedef struct	s_table
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
	pthread_mutex_t	stop_mutex;
	pthread_mutex_t meal_mutex;
	t_philo	*philos;
}	t_table;

long	get_time(void);
long	timestamp_ms(long start_time);
int	ft_atoi_positive(const char *str);
void	precise_sleep(long time, t_table *table);
void	print_state(t_philo *philo, char *msg);
int	get_stop(t_table *table);
void	set_stop(t_table *table, int value);
int	parse_args(t_table *table, int argc, char **argv);
int	init_table(t_table *table);
int	init_philos(t_table *table);
void	join_threads(t_table *table);
void	cleanup(t_table *table);
void	*routine(void *arg);
int	monitor_simulation(t_table *table);
int	start_threads(t_table *table);

#endif
