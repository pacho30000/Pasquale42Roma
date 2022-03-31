/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 23:48:51 by pcatapan          #+#    #+#             */
/*   Updated: 2022/04/01 00:09:46 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

pid_t	ft_atoii(char *pid)
{
	int		i;
	pid_t	res;

	i = 0;
	res = 0;
	while (pid[i])
	{
		res = res * 10 + pid[i] - 48;
		i++;
	}
	return (res);
}

int	ft_check_pid(char *pid)
{
	int	i;

	i = 0;
	while (pid[i])
	{
		if (!(pid[i] >= 48 && pid[i] <= 57))
		{
			ft_printf("ERROR : Invalid PID!\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_send_char(char lett, int pid)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (i < 8)
	{
		usleep(42);
		if (lett & 1)
			res += kill(pid, SIGUSR1);
		else
			res += kill(pid, SIGUSR2);
		lett = lett >> 1;
		i++;
	}
	return (res);
}

void	ft_send_message(char *message, pid_t pid)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (message[i])
	{
		res += ft_send_char(message[i], pid);
		i++;
	}
	res += ft_send_char('\0', pid);
	if (res == 0)
		ft_printf("GOOD : Message sending\n");
	else
		ft_printf("ERROR : Something went wrong!\n");
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc != 3)
	{
		ft_printf("ERROR : Invalid number of arguments!\n");
		return (0);
	}
	if (ft_check_pid(argv[1]) == 1)
		return (0);
	pid = ft_atoii(argv[1]);
	ft_send_message(argv[2], pid);
}
