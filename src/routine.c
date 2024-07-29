/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 22:46:17 by dolifero          #+#    #+#             */
/*   Updated: 2024/07/29 19:12:05 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_take_forks(t_philo *philo, t_data *data)
{
	int	left_fork;
	int	right_fork;

	left_fork = philo->num;
	right_fork = (philo->num + 1) % data->philo_amount;
	if (philo->num % 2 == 0)
	{
		pthread_mutex_lock(&data->forks[left_fork]);
		print_action(data, philo, "has taken a fork");
		pthread_mutex_lock(&data->forks[right_fork]);
		print_action(data, philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(&data->forks[right_fork]);
		print_action(data, philo, "has taken a fork");
		pthread_mutex_lock(&data->forks[left_fork]);
		print_action(data, philo, "has taken a fork");
	}
}

void	ft_unlock_forks(t_philo *philo, t_data *data)
{
	int	left_fork;
	int	right_fork;

	left_fork = philo->num;
	right_fork = (philo->num + 1) % data->philo_amount;
	if (philo->num % 2 == 0)
	{
		pthread_mutex_unlock(&data->forks[right_fork]);
		pthread_mutex_unlock(&data->forks[left_fork]);
	}
	else
	{
		pthread_mutex_unlock(&data->forks[left_fork]);
		pthread_mutex_unlock(&data->forks[right_fork]);
	}
}

void	ft_eat(t_philo *philo, t_data *data)
{
	ft_take_forks(philo, data);
	pthread_mutex_lock(&philo->mutex);
	philo->last_meal_time = ft_get_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->mutex);
	print_action(data, philo, "is eating");
	ft_usleep(data->eat_time * 1000);
	ft_unlock_forks(philo, data);
}

void	ft_sleep(t_philo *philo, t_data *data)
{
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
	while (!ft_someone_dead(data))
	{
		print_action(data, philo, "is thinking");
		ft_eat(philo, data);
		ft_sleep(philo, data);
		pthread_mutex_lock(&data->full_checker);
		if (data->meal_amount != -1 && philo->meals_eaten >= data->meal_amount)
		{
			philo->finished = 1;
			data->full++;
			pthread_mutex_unlock(&data->full_checker);
			break ;
		}
		pthread_mutex_unlock(&data->full_checker);
		if (data->philo_amount % 2 == 1)
			usleep(1000);
	}
	return (NULL);
}
