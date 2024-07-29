/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_monitor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 21:18:13 by dolifero          #+#    #+#             */
/*   Updated: 2024/07/29 19:13:27 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	check_all_finished(t_data *data)
{
	pthread_mutex_lock(&data->full_checker);
	if (data->full == data->philo_amount)
		return (pthread_mutex_unlock(&data->full_checker), 1);
	pthread_mutex_unlock(&data->full_checker);
	return (0);
}

void	set_dead(t_data *data)
{
	pthread_mutex_lock(&data->death_checker);
	data->someone_died = 1;
	pthread_mutex_unlock(&data->death_checker);
}

int	ft_starved_check(t_philo *philo, t_data *data)
{
	long long	time_since_meal;
	long long	time;

	time = ft_get_time();
	time_since_meal = time - philo->last_meal_time;
	if (time_since_meal > data->die_time && !philo->finished)
	{
		set_dead(data);
		print_action_death(data, philo);
		return (1);
	}
	return (0);
}

void	*death_monitor(void *arg)
{
	t_data	*data;
	int		i;

	data = (t_data *)arg;
	while (1)
	{
		i = 0;
		while (i < data->philo_amount)
		{
			pthread_mutex_lock(&data->philos[i].mutex);
			if (ft_starved_check(&data->philos[i], data))
				return (pthread_mutex_unlock(&data->philos[i].mutex), NULL);
			pthread_mutex_unlock(&data->philos[i].mutex);
			i++;
		}
		if (check_all_finished(data))
			return (NULL);
		if (data->philo_amount % 2 == 1)
			usleep(1000);
	}
	return (NULL);
}

void	monitor_init(t_data *data)
{
	pthread_t	monitor;
	int			i;

	i = 0;
	data->start_time = ft_get_time();
	create_philo_threads(data);
	if (pthread_create(&monitor, NULL, death_monitor, data) != 0)
	{
		free_data(data);
		exit(EXIT_FAILURE);
	}
	pthread_join(monitor, NULL);
	if (data->philo_amount == 1 && data->someone_died == 1)
	{
		free_data(data);
		exit(EXIT_SUCCESS);
	}
	i = 0;
	while (i < data->philo_amount)
	{
		pthread_join(data->philos[i].thread, NULL);
		i++;
	}
}
