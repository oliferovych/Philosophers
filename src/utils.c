/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 19:34:38 by dolifero          #+#    #+#             */
/*   Updated: 2024/07/27 17:17:37 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	negativity;
	int	result;

	negativity = 1;
	i = 0;
	result = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
		|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
		i++;
	if ((str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			negativity *= (-1);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	return (result * negativity);
}

void	print_action(t_data *data, t_philo *philo, const char *str)
{
	pthread_mutex_lock(&data->print_mutex);
	if (ft_someone_dead(data))
	{
		pthread_mutex_unlock(&data->print_mutex);
		return ;
	}
	printf("%lld %d %s\n", (ft_get_time() - data->start_time),
		(philo->num + 1), str);
	pthread_mutex_unlock(&data->print_mutex);
}

void	print_action_death(t_data *data, t_philo *philo)
{
	pthread_mutex_lock(&data->print_mutex);
	printf("%lld %d %s\n", (ft_get_time() - data->start_time),
		(philo->num + 1), "died");
	pthread_mutex_unlock(&data->print_mutex);
}

int	ft_isnum(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_someone_dead(t_data *data)
{
	pthread_mutex_lock(&data->death_checker);
	if (data->someone_died)
	{
		pthread_mutex_unlock(&data->death_checker);
		return (1);
	}
	pthread_mutex_unlock(&data->death_checker);
	return (0);
}
