/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 22:46:17 by dolifero          #+#    #+#             */
/*   Updated: 2024/07/17 23:14:19 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;
	t_data	*data;
	int		left_fork;
	int		right_fork;

	philo = (t_philo *)arg;
	data = ft_get_data();
	left_fork = philo->num;
	right_fork = (philo->num + 1) % data->philo_amount;
	if (philo->num % 2 == 0)
		ft_usleep(data->eat_time / 2);
	while (1)
	{

		if (data->meal_amount != -1 && philo->meals_eaten >= data->meal_amount)
			break;
	}
	return (NULL);
}
