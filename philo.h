/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 19:01:10 by dolifero          #+#    #+#             */
/*   Updated: 2024/07/16 21:39:28 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_philo
{
	int	num;
	int	death_time;
	int	eat_time;
	int	sleep_time;
	int	meal_amount;
}				t_philo;

#endif
