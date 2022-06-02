/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 18:22:55 by pcatapan          #+#    #+#             */
/*   Updated: 2022/06/02 20:27:33 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>
# include <pthread.h>
# include <sys/time.h>

# define ERROR_NUMBER_ARGUMENTS	-1
# define ERROR_ARGUMENTS	-2

typedef struct s_philosophers
{
	pthread_t		philosophers_thread;
	pthread_t		check_death_philosophers;
	int				philosophers_number;
	int				last_eat;
	int				count;
	int				left_fork;
	int				right_fork;
	int				is_eating;
	pthread_mutex_t	mutex_eating;
	struct s_main	*istance;
}				t_philosophers;

typedef struct s_main
{
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_philosopher_must_eat;
	int				error;
	int				time;
	int				stop;
	t_philosophers	**philosophers;
	pthread_mutex_t	mutex_write;
	pthread_mutex_t	*forks;
}				t_main;

// Utils.c
int				ft_atoi(const char *str, int *par);
void			ft_error(t_main *istance);
int				ft_get_time(void);
void			ft_usleep(uint64_t time_in_ms);
void			ft_message_shell(t_main *istance, int philosophers_number, \
								char *txt);

// Starter.c
t_philosophers	**ft_philosophers_start(t_main *istance);
pthread_mutex_t	*ft_start_fork(t_main *istance);
int				ft_check_arguments(int argc, char **argv, t_main *istance);
void			ft_take_fork(t_philosophers *philo);
t_main			*init(int ac, char **av);

#endif