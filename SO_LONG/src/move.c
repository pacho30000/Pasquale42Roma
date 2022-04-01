/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 06:38:52 by pcatapan          #+#    #+#             */
/*   Updated: 2022/04/01 02:12:12 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_quit(t_map *map)
{
	exit (0);
}

void	ft_move_enemy(t_map *map)
{
	ft_move_pink_x(map);
	map->enemy[map->pink->x][map->pink->y] = 'P';
	ft_move_blu_x(map);
	map->enemy[map->blu->x][map->blu->y] = 'B';
	ft_move_oran(map);
	map->enemy[map->oran->x][map->oran->y] = 'O';
}

/*
Freccia UP(126) -- Freccia DW(125); 
Freccia DX(124) -- Freccia SX(123)
W(13) --- A(0) --- S(1) --- D(2)
ESC(53)--- Invio(36) --- Tab(49)
*/
int	ft_controll_key(int key, t_map *map)
{
	map->map[map->pacman->x][map->pacman->y] = '0';
	if (map->death == 1)
		exit (0);
	if (key == 13 || key == 126)
		ft_pacman_up(map);
	if (key == 125 || key == 1)
		ft_pacman_dw(map);
	if (key == 124 || key == 2)
		ft_pacman_dx(map);
	if (key == 123 || key == 0)
		ft_pacman_sx(map);
	ft_printf("MOVES : %d\n", map->moves);
	if (key == 53)
		exit (0);
	if (map->object->enemy > 0)
		ft_move_enemy(map);
	ft_print_map_in_shell(map, map->enemy);
	return (0);
}

void	ft_move(t_map *map)
{
	map->t_img = 1;
	map->oran->dir = 0;
	map->blu->dir = 0;
	map->moves = 0;
	map->enemy[map->pacman->x][map->pacman->y] = '0';
	mlx_do_key_autorepeaton(map->mlx_ptr);
	mlx_hook(map->window, 2, 1L << 0, &ft_controll_key, map);
	mlx_hook(map->window, 17, 1L << 17, &ft_quit, map);
}
