/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 19:01:10 by dolifero          #+#    #+#             */
/*   Updated: 2024/07/17 22:54:39 by dolifero         ###   ########.fr       */
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

typedef __useconds_t useconds_t;

typedef struct s_philo
{
	int			num;
	int			meals_eaten;
	long long	last_meal_t;
	int			left_fork;
	int			right_fork;
	pthread_t	thread;
}				t_philo;

typedef struct s_data
{
	int				philo_amount;
	useconds_t		sleep_time;
	useconds_t		eat_time;
	useconds_t		die_time;
	int				meal_amount;
	useconds_t		start_time;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
}				t_data;

//ROUTINE
void		*routine(void *arg);
//STATIC
t_data		*ft_get_data(void);
//PARSING
int			check_args(char **argv, int argc);
int			parse_args(char **argv, int argc, t_data *data);
//UTILS
long long	ft_get_time(void);
void		ft_usleep(useconds_t usec);
int			ft_atoi(const char *str);

#endif
