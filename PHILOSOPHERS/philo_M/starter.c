/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 19:37:47 by pcatapan          #+#    #+#             */
/*   Updated: 2022/06/02 20:05:28 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_check_arguments(int argc, char **argv, t_main *istance)
{
	if (argc < 5 || argc > 6)
	{
		istance->error = ERROR_NUMBER_ARGUMENTS;
		return (ERROR_NUMBER_ARGUMENTS);
	}
	if (ft_atoi(argv[1], &istance->number_of_philosophers) \
	|| ft_atoi(argv[2], &istance->time_to_die) \
	|| ft_atoi(argv[3], &istance->time_to_eat) \
	|| ft_atoi(argv[4], &istance->time_to_sleep))
	{
		istance->error = ERROR_ARGUMENTS;
		return (ERROR_ARGUMENTS);
	}
	istance->number_philosopher_must_eat = 0;
	if (argc == 6)
	{
		if (ft_atoi(argv[5], &istance->number_philosopher_must_eat))
		{
			istance->error = ERROR_ARGUMENTS;
			return (ERROR_ARGUMENTS);
		}
	}
	return (0);
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
	t_philosophers	**philo;
	int				i;

	philo = (t_philosophers **)malloc(sizeof(t_philosophers *) * \
									istance->number_of_philosophers);
	if (!philo)
		return (NULL);
	i = 0;
	while (i < (int)istance->number_of_philosophers)
	{
		philo[i] = (t_philosophers *)malloc(sizeof(t_philosophers) * 1);
		if (!philo[i])
			return (NULL);
		if (pthread_mutex_init(&philo[i]->mutex_eating, NULL))
			return (NULL);
		philo[i]->philosophers_number = i;
		philo[i]->istance = istance;
		philo[i]->is_eating = false;
		philo[i]->count = 0;
		philo[i]->left_fork = i;
		philo[i]->right_fork = (i + 1) % istance->number_of_philosophers;
		i++;
	}
	return (philo);
}

void	ft_take_fork(t_philosophers *philo)
{
	pthread_mutex_lock(&philo->istance->forks[philo->left_fork]);
	pthread_mutex_lock(&philo->istance->forks[philo->right_fork]);
	ft_message_shell(philo->istance, philo->philosophers_number, \
		"has taken the left and right fork");
	pthread_mutex_lock(&philo->mutex_eating);
	philo->last_eat = ft_get_time();
	philo->is_eating = true;
	ft_message_shell(philo->istance, philo->philosophers_number, "is eating");
	ft_usleep(philo->istance->time_to_eat);
	philo->is_eating = false;
	philo->count++;
	pthread_mutex_unlock(&philo->mutex_eating);
}
