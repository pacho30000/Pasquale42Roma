/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 19:54:09 by pcatapan          #+#    #+#             */
/*   Updated: 2022/03/10 06:11:47 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx/mlx.h"
# include "./PRINTF/ft_printf.h"
# include "./GET_NEXT_LINE/get_next_line.h"
# include <unistd.h>
# include <fcntl.h>

typedef struct s_map
{
	int	h;
	int	w;
	int	read;
}	t_map;

int	ft_checker(int argc, char **argv, t_map *map);

#endif