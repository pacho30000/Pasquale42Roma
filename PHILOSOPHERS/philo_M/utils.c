/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 18:49:40 by pcatapan          #+#    #+#             */
/*   Updated: 2022/06/02 18:18:57 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_error(t_main *istance)
{
	if (istance->error == ERROR_NUMBER_ARGUMENTS)
		printf("Error with number of arguments!");
	if (istance->error == ERROR_ARGUMENTS)
		printf("Error the arguments have a invalid charter!");
}

void	ft_message_shell(t_main *istance, int philosophers_number, char *txt)
{
	pthread_mutex_lock(&istance->mutex_write);
	printf("[%d]\tPhilosopher %d %s\n", ft_get_time() - istance->time,
		philosophers_number + 1, txt);
	if (txt[0] != 'd')
		pthread_mutex_unlock(&istance->mutex_write);
}

int	ft_get_time(void)
{
	static struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * (uint64_t)1000) + (tv.tv_usec / 1000));
}

void	ft_usleep(uint64_t time_in_ms)
{
	uint64_t	start;

	start = 0;
	start = ft_get_time();
	while ((ft_get_time() - start) < time_in_ms)
		usleep(time_in_ms / 10);
}

int	ft_atoi(const char *str, int *par)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 48 || str[i] > 57)
			return (true);
		num = num * 10 + (str[i] - '0');
		i++;
	}
	*par = num;
	return (false);
}
