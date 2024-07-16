/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 20:01:23 by dolifero          #+#    #+#             */
/*   Updated: 2024/07/16 20:18:30 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	parse_args(char **argv, int argc, t_philo **philo)
{
	int	philo_amount;
	int	i;

	i = 0;
	philo_amount = atoi(argv[1]);
	philo = malloc(sizeof(t_philo) * philo_amount + 1);
	while (i < philo_amount)
	{
		philo[i]->num = i + 1;
		if (argv[5] != NULL)
			philo[i]->meal_amount = atoi(argv[5]);

	}

}
