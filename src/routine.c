/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 22:46:17 by dolifero          #+#    #+#             */
/*   Updated: 2024/07/22 21:48:13 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	eat(t_philo *philo, t_data *data)
{
	int		left_fork;
	int		right_fork;

	left_fork = philo->num;
	right_fork = (philo->num + 1) % data->philo_amount;
	pthread_mutex_lock(&data->forks[left_fork]);
	print_action(data, philo, "has taken 1 fork");
	pthread_mutex_lock(&data->forks[right_fork]);
	print_action(data, philo, "has taken 2 fork");
	pthread_mutex_lock(&data->death_checker);
	philo->last_meal_time = ft_get_time();
	pthread_mutex_unlock(&data->death_checker);
	print_action(data, philo, "is eating");
	usleep(data->eat_time * 1000);
	philo->meals_eaten++;
	pthread_mutex_unlock(&data->forks[right_fork]);
	pthread_mutex_unlock(&data->forks[left_fork]);
}

void	*routine(void *arg)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)arg;
	data = philo->data;
	if (philo->num % 2 == 0)
		ft_usleep(data->eat_time / 2);
	while (1)
	{
		if (data->someone_died)
			break ;
		print_action(data, philo, "is thinking");
		if (data->someone_died)
			break ;
		eat(philo, data);
		if (data->someone_died)
			break ;
		print_action(data, philo, "is sleeping");
		usleep(data->sleep_time * 1000);
		if (data->meal_amount != -1 && philo->meals_eaten >= data->meal_amount)
			break ;
	}
	return (NULL);
}
