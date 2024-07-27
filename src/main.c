/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 19:19:52 by dolifero          #+#    #+#             */
/*   Updated: 2024/07/27 18:54:23 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

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
