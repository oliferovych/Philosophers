/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 19:19:52 by dolifero          #+#    #+#             */
/*   Updated: 2024/07/16 21:39:56 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	main(int argc, char **argv)
{
	t_philo	*philo;

	if (argc < 5 || argc > 6)
		return (printf("Insufficient number of arguments.\n"), EXIT_FAILURE);

	printf("Shall thy path begin here\n");
	return (EXIT_SUCCESS);
}
