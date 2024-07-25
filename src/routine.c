/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 22:46:17 by dolifero          #+#    #+#             */
/*   Updated: 2024/07/25 15:59:58 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_eat(t_philo *philo, t_data *data)
{
	int		left_fork;
	int		right_fork;

	if (data->someone_died)
		return ;
	left_fork = philo->num;
	right_fork = (philo->num + 1) % data->philo_amount;
	pthread_mutex_lock(&data->forks[left_fork]);
	print_action(data, philo, "has taken a fork");
	pthread_mutex_lock(&data->forks[right_fork]);
	print_action(data, philo, "has taken a fork");
	pthread_mutex_lock(&data->death_checker);
	philo->last_meal_time = ft_get_time();
	pthread_mutex_unlock(&data->death_checker);
	print_action(data, philo, "is eating");
	ft_usleep(data->eat_time * 1000);
	philo->meals_eaten++;
	pthread_mutex_unlock(&data->forks[right_fork]);
	pthread_mutex_unlock(&data->forks[left_fork]);
}

void	ft_sleep(t_philo *philo, t_data *data)
{
	if (data->someone_died)
		return ;
	print_action(data, philo, "is sleeping");
	ft_usleep(data->sleep_time * 1000);
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
		ft_eat(philo, data);
		ft_sleep(philo, data);
		pthread_mutex_lock(&data->death_checker);
		if (data->meal_amount != -1 && philo->meals_eaten >= data->meal_amount)
		{
			philo->finished = 1;
			data->full++;
			pthread_mutex_unlock(&data->death_checker);
			break ;
		}
		pthread_mutex_unlock(&data->death_checker);
	}
	return (NULL);
}
