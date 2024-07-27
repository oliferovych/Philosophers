/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 16:08:04 by dolifero          #+#    #+#             */
/*   Updated: 2024/07/27 18:42:21 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

long long	ft_get_time_micro(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000000) + time.tv_usec);
}

void	ft_usleep(long long usec)
{
	long long start = ft_get_time_micro();
	long long elapsed = 0;
	const long long sleep_interval = 100;

	while (elapsed < usec)
	{
		usleep(sleep_interval);
		elapsed = ft_get_time_micro() - start;
	}
}

long long	ft_get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}
