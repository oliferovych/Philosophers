/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 19:01:10 by dolifero          #+#    #+#             */
/*   Updated: 2024/07/25 16:43:35 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <sys/types.h>

typedef struct s_philo
{
	int				num;
	int				meals_eaten;
	long long		last_meal_time;
	int				left_fork;
	int				right_fork;
	int				finished;
	pthread_t		thread;
	struct s_data	*data;
}				t_philo;

typedef struct s_data
{
	int				philo_amount;
	useconds_t		sleep_time;
	useconds_t		eat_time;
	useconds_t		die_time;
	int				full;
	int				meal_amount;
	long long		start_time;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	death_checker;
	int				someone_died;
}				t_data;

//ROUTINE
void		*routine(void *arg);
void		monitor_init(t_data *data);
//PARSING
int			check_args(char **argv, int argc);
int			parse_args(char **argv, int argc, t_data *data);
//UTILS
void		print_action(t_data *data, t_philo *philo, const char *str);
void		print_action_death(t_data *data, t_philo *philo);
long long	ft_get_time(void);
long long	ft_get_time_micro(void);
void		ft_usleep(long long usec);
int			ft_atoi(const char *str);
int			ft_isnum(char c);
//FREEING
void		free_data(t_data *data);
//DEBUG
void		ft_print_data(t_data *data);

#endif
