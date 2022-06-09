/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 23:37:51 by pcatapan          #+#    #+#             */
/*   Updated: 2022/06/09 16:49:01 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_destroy(t_main *istance)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&istance->mutex_write);
	pthread_mutex_destroy(istance->forks);
	pthread_mutex_destroy(&istance->mutex_stop);
	while (i < istance->number_of_philosophers)
	{
		pthread_mutex_destroy(&istance->philosophers[i]->mutex_last_eat);
		pthread_mutex_destroy(&istance->philosophers[i]->mutex_eating);
		pthread_mutex_destroy(&istance->philosophers[i]->mutex_count);
		//free (&istance->philosophers[i]);
		i++;
	}
	i = 0;
	// while (i < istance->number_of_philosophers)
	// {
	// 	pthread_join(istance->philosophers[i]->philosophers_thread, NULL);
	// 	i++;
	// }
	i = 0;
	free (istance->forks);
	free (istance->philosophers);
}
