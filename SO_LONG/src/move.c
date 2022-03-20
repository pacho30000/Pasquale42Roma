/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 06:38:52 by pcatapan          #+#    #+#             */
/*   Updated: 2022/03/20 05:47:14 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*
Freccia UP(126) -- Freccia DW(125); 
Freccia DX(124) -- Freccia SX(123)
W(13) --- A(0) --- S(1) --- D(2)
ESC(53)--- Invio(36) --- Tab(49)
*/
int	ft_controll_key(int key, t_map *map)
{
	map->map[map->pacman.x][map->pacman.y] = '0';
	if (key == 13 || key == 126)
		ft_pacman_up(map);
	if (key == 125 || key == 1)
		ft_pacman_dw(map);
	if (key == 124 || key == 2)
		ft_pacman_dx(map);
	if (key == 123 || key == 0)
		ft_pacman_sx(map);
	// if (key == 53)
	// 	ft_quit;
	// if (key == 36 || key == 49)
	// 	ft_start;
	return (0);
}

void	ft_move(t_map *map)
{
	mlx_hook(map->window, 2, 1L << 0, &ft_controll_key, map);
}