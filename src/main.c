/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 19:19:52 by dolifero          #+#    #+#             */
/*   Updated: 2024/07/17 22:44:17 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

t_data	*ft_get_data(void)
{
	static t_data	*data;

	if (!data)
	{
		data = malloc(sizeof(data));
		if (!data)
			return (NULL);
	}
	return (&data);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (!check_args(argv, argc))
		return (EXIT_FAILURE);
	if (!parse_args(argv, argc, ft_get_data()))
		return (EXIT_FAILURE);
	printf("Shall thy path begin here\n");
	return (EXIT_SUCCESS);
}
