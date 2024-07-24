/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_monitor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 21:18:13 by dolifero          #+#    #+#             */
/*   Updated: 2024/07/22 21:21:31 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*death_monitor(void *arg)
{
	t_data	*data;
	int		i;

	i = 0;
	data = (t_data *)arg;
	while (1)
	{
		while (i < data->philo_amount)
		{
			pthread_mutex_lock(&data->death_checker);
			if (ft_get_time() - data->philos[i].last_meal_time > data->die_time)
			{
				print_action(data, &data->philos[i], "died");
				data->someone_died = 1;
				pthread_mutex_unlock(&data->death_checker);
				return (NULL);
			}
			pthread_mutex_unlock(&data->death_checker);
			i++;
		}
		usleep(1000);
		if (data->someone_died)
			break ;
	}
	return (NULL);
}

void	monitor_init(t_data *data)
{
	pthread_t	monitor;
	int			i;

	i = 0;
	if (pthread_create(&monitor, NULL, death_monitor, data) != 0)
	{
		free_data(data);
		exit(EXIT_FAILURE);
	}
	pthread_join(monitor, NULL);
	while (i < data->philo_amount)
	{
		pthread_join(data->philos[i].thread, NULL);
		i++;
	}
}