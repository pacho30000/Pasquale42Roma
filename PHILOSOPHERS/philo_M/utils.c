/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 18:49:40 by pcatapan          #+#    #+#             */
/*   Updated: 2022/06/08 23:49:59 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_check_arguments(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (ERROR_NUMBER_ARGUMENTS);
	if (ft_atoi(argv[1]) || ft_atoi(argv[2]) \
	|| ft_atoi(argv[3]) || ft_atoi(argv[4]))
		return (ERROR_ARGUMENTS);
	if (ft_convert(argv[1]) <= 0)
		return (ERROE_ZERO);
	if (argc == 6)
	{
		if (ft_atoi(argv[5]))
			return (ERROR_ARGUMENTS);
	}
	return (0);
}

int	ft_get_time(void)
{
	static struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * (uint64_t)1000) + (t.tv_usec / 1000));
}

void	ft_usleep(uint64_t time_in_ms)
{
	uint64_t	start;

	start = 0;
	start = ft_get_time();
	while (1)
	{
		if ((ft_get_time() - start) >= time_in_ms)
			break ;
		usleep(100);
	}
}

int	ft_convert(const char *str)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	while (str[i] != '\0')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num);
}

int	ft_atoi(const char *str)
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
	return (false);
}
