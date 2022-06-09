/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_rice.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 23:26:56 by pcatapan          #+#    #+#             */
/*   Updated: 2022/06/09 16:56:50 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_mutex_stop(t_main *istance)
{
	int	rtr;

	pthread_mutex_lock(&istance->mutex_stop);
	rtr = istance->stop;
	pthread_mutex_unlock(&istance->mutex_stop);
	return (rtr);
}

int	ft_mutex_last_eat(t_philosophers *philo)
{
	int	rtr;

	pthread_mutex_lock(&philo->mutex_last_eat);
	rtr = philo->last_eat;
	pthread_mutex_unlock(&philo->mutex_last_eat);
	return (rtr);
}

int	ft_mutex_count(t_philosophers *philo)
{
	int	rtr;

	pthread_mutex_lock(&philo->mutex_count);
	rtr = philo->count;
	pthread_mutex_unlock(&philo->mutex_count);
	return (rtr);
}
