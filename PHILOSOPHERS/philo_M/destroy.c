/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 23:37:51 by pcatapan          #+#    #+#             */
/*   Updated: 2022/06/08 00:09:00 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_destroy(t_main *istance)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&istance->mutex_write);
	pthread_mutex_destroy(istance->forks);
	while (i < istance->number_of_philosophers)
	{
		pthread_mutex_destroy(&istance->philosophers[i]->mutex_eating);
		i++;
	}
	i = 0;
	while (i < istance->number_of_philosophers)
	{
		//pthread_join(istance->philosophers[i]->philosophers_thread, NULL);
		//pthread_join(istance->philosophers[i]->philosophers_thread, NULL);
		i++;
	}
	free (istance->forks);
	free (istance->philosophers);
}
