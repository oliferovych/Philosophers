/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 19:19:52 by dolifero          #+#    #+#             */
/*   Updated: 2024/07/22 21:26:24 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_print_data(t_data *data)
{
	printf("philo_count: %d\n", data->philo_amount);
	printf("time_to_die: %d\n", data->die_time);
	printf("time_to_eat: %d\n", data->eat_time);
	printf("time_to_sleep: %d\n", data->sleep_time);
	printf("meal_count: %d\n", data->meal_amount);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (!check_args(argv, argc))
		return (EXIT_FAILURE);
	if (!parse_args(argv, argc, &data))
		return (EXIT_FAILURE);
	monitor_init(&data);
	free_data(&data);
	return (EXIT_SUCCESS);
}
