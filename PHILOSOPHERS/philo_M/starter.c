/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 19:37:47 by pcatapan          #+#    #+#             */
/*   Updated: 2022/06/09 17:08:58 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_main	*ft_start(int argc, char **argv)
{
	t_main	*istance;

	istance = malloc(sizeof(t_main) * 1);
	if (!istance)
		return (NULL);
	istance->number_of_philosophers = ft_convert(argv[1]);
	istance->time_to_die = ft_convert(argv[2]);
	istance->time_to_eat = ft_convert(argv[3]);
	istance->time_to_sleep = ft_convert(argv[4]);
	istance->number_philosopher_must_eat = 0;
	if (argc == 6)
		istance->number_philosopher_must_eat = ft_convert(argv[5]);
	pthread_mutex_init(&istance->mutex_write, NULL);
	pthread_mutex_init(&istance->mutex_stop, NULL);
	istance->forks = ft_start_fork(istance);
	istance->philosophers = ft_philosophers_start(istance);
	if (!istance->philosophers || !istance->forks)
		return (0);
	return (istance);
}

/*
Create the fork
*/
pthread_mutex_t	*ft_start_fork(t_main *istance)
{
	pthread_mutex_t	*forks;
	int				i;

	i = 0;
	forks = malloc(sizeof(pthread_mutex_t) * istance->number_of_philosophers);
	if (!forks)
		return (NULL);
	while (i < istance->number_of_philosophers)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
	return (forks);
}

/*
Create the philosophers.
Only philosophers have two fork assigend, use the module beacuse
when "i" is equal to number_of_philosophers the rest is 0
*/
t_philosophers	**ft_philosophers_start(t_main *istance)
{
	int				i;
	t_philosophers	**philo;

	philo = (t_philosophers **)malloc(sizeof(t_philosophers *) * \
									istance->number_of_philosophers);
	if (!philo)
		return (NULL);
	i = -1;
	while (++i < (int)istance->number_of_philosophers)
	{
		philo[i] = (t_philosophers *)malloc(sizeof(t_philosophers) * 1);
		if (!philo[i])
			return (NULL);
		if (pthread_mutex_init(&philo[i]->mutex_eating, NULL) || \
			pthread_mutex_init(&philo[i]->mutex_last_eat, NULL) || \
			pthread_mutex_init(&philo[i]->mutex_count, NULL))
			return (NULL);
		philo[i]->philosophers_number = i;
		philo[i]->istance = istance;
		philo[i]->is_eating = 0;
		philo[i]->count = 0;
		philo[i]->left_fork = i;
		philo[i]->right_fork = (i + 1) % istance->number_of_philosophers;
	}
	return (philo);
}

void	ft_take_fork(t_philosophers *philo)
{
	pthread_mutex_lock(&philo->istance->forks[philo->left_fork]);
	ft_message_shell(philo->istance, philo->philosophers_number, \
		"has taken the left");
	pthread_mutex_lock(&philo->istance->forks[philo->right_fork]);
	ft_message_shell(philo->istance, philo->philosophers_number, \
		"has taken the right");
	pthread_mutex_lock(&philo->mutex_eating);
	pthread_mutex_lock(&philo->mutex_last_eat);
	pthread_mutex_lock(&philo->mutex_count);
	philo->last_eat = ft_get_time();
	philo->is_eating = 1;
	ft_message_shell(philo->istance, philo->philosophers_number, "is eating");
	ft_usleep(philo->istance->time_to_eat);
	philo->is_eating = 0;
	philo->count++;
	pthread_mutex_unlock(&philo->mutex_eating);
	pthread_mutex_unlock(&philo->mutex_count);
	pthread_mutex_unlock(&philo->mutex_last_eat);
}
