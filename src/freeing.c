/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 20:50:35 by dolifero          #+#    #+#             */
/*   Updated: 2024/07/27 17:16:20 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	free_data(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_amount)
	{
		pthread_mutex_destroy(&data->forks[i]);
		pthread_mutex_destroy(&data->philos[i].mutex);
		i++;
	}
	pthread_mutex_destroy(&data->death_checker);
	pthread_mutex_destroy(&data->print_mutex);
	pthread_mutex_destroy(&data->full_checker);
	free(data->philos);
	free(data->forks);
}
