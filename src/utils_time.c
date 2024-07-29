/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 16:08:04 by dolifero          #+#    #+#             */
/*   Updated: 2024/07/29 19:10:41 by dolifero         ###   ########.fr       */
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
	long long		start;
	long long		elapsed;
	long long		sleep_interval;

	sleep_interval = 500;
	start = ft_get_time_micro();
	elapsed = 0;
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
