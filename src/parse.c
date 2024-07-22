/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 20:01:23 by dolifero          #+#    #+#             */
/*   Updated: 2024/07/22 21:27:33 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	check_args(char **argv, int argc)
{
	int	i;
	int	j;

	i = 1;
	if (argc < 5 || argc > 6)
		return (printf("Insufficient number of arguments.\n"), 0);
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (!ft_isnum(argv[i][j]))
				return (printf("Non-numeric arguments\n"), 0);
			j++;
		}
		i++;
	}
	return (1);
}

int	mutex_init(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_amount)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
		{
			free(data->forks);
			free(data);
			return (0);
		}
		i++;
	}
	if (pthread_mutex_init(&data->print_mutex, NULL) != 0
		|| pthread_mutex_init(&data->death_checker, NULL) != 0)
	{
		free(data->forks);
		free(data);
		return ((void)printf("i fail here\n"), 0);
	}
	return (1);
}

int	philos_init(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_amount)
	{
		data->philos[i].num = i;
		data->philos[i].meals_eaten = 0;
		data->philos[i].last_meal_time = data->start_time;
		data->philos[i].data = data;
		if (pthread_create(&data->philos[i].thread, NULL,
				routine, &data->philos[i]) != 0)
		{
			free(data->forks);
			free(data->philos);
			free(data);
			return (-1);
		}
		i++;
	}
	return (1);
}

int	parse_args(char **argv, int argc, t_data *data)
{
	data->philo_amount = ft_atoi(argv[1]);
	data->die_time = ft_atoi(argv[2]);
	data->eat_time = ft_atoi(argv[3]);
	data->sleep_time = ft_atoi(argv[4]);
	data->someone_died = 0;
	if (argc == 6)
		data->meal_amount = ft_atoi(argv[5]);
	else
		data->meal_amount = -1;
	data->start_time = ft_get_time();
	data->philos = malloc(sizeof(t_philo) * data->philo_amount);
	if (!data->philos)
		return (-1);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->philo_amount);
	if (!data->forks)
		return (-1);
	if (!mutex_init(data))
		return (-1);
	ft_print_data(data);
	if (!philos_init(data))
		return (-1);
	return (1);
}
