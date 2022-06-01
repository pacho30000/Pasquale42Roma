/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 18:22:55 by pcatapan          #+#    #+#             */
/*   Updated: 2022/06/01 19:39:43 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdlib.h>
# include <stdlib.h>
# include <stdio.h>
# include "./PRINTF/ft_printf.h"
# include <pthread.h>
# include <sys/time.h>

typedef struct s_main
{
	int	number_of_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_times_each_philosopher_must_eat;
}				t_main;

// Utils.c
int	ft_atoi(const char *str);

// Checker.c
int	ft_check_arguments(int argc, char **argv, t_main istance);

#endif