/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 22:24:36 by pcatapan          #+#    #+#             */
/*   Updated: 2022/06/08 23:02:44 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_error(int error)
{
	if (error == ERROR_NUMBER_ARGUMENTS)
	{
		printf("Error with number of arguments!");
		return (1);
	}
	if (error == ERROR_ARGUMENTS)
	{
		printf("Error the arguments have a invalid charter!");
		return (1);
	}
	if (error == ERROE_ZERO)
	{
		printf("Error the philospher is 0!");
		return (1);
	}
	return (0);
}

void	ft_message_shell(t_main *istance, int philosophers_number, char *txt)
{
	pthread_mutex_lock(&istance->mutex_write);
	printf("[%d]\tPhilosopher %d %s\n", ft_get_time() - istance->time,
		philosophers_number + 1, txt);
	if (txt[0] != 'd')
		pthread_mutex_unlock(&istance->mutex_write);
}
