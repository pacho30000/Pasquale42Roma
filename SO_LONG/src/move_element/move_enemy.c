/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 06:22:00 by pcatapan          #+#    #+#             */
/*   Updated: 2022/05/04 17:49:24 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static void	ft_move_noblock(t_map *map, int x, int y)
{
	if (ft_can_enemy(map, x + 1, y) == 1)
	{
		ft_put_back_enemy(map, x, y);
		ft_new_i(map, x + 1, y, map->img->oran_dw);
		map->map[x][y] = 'N';
		x++;
	}
	else if (ft_can_enemy(map, x, y - 1) == 1)
	{
		ft_put_back_enemy(map, x, y);
		ft_new_i(map, x, y - 1, map->img->oran_sx);
		map->map[x][y] = 'N';
		y--;
	}
}

void	ft_move_oran_y(t_map *map, int x, int y)
{
	if (map->pacman->y < y)
	{
		if (ft_can_enemy(map, x, y - 1) == 1)
		{
			ft_put_back_enemy(map, x, y);
			ft_new_i(map, x, y - 1, map->img->oran_sx);
			map->map[x][y] = 'N';
			y--;
		}
		else
			ft_move_noblock(map, x, y);
	}
	else if (map->pacman->y > y)
	{
		if (ft_can_enemy(map, x, y + 1) == 1)
		{
			ft_put_back_enemy(map, x, y);
			ft_new_i(map, x, y + 1, map->img->oran_dx);
			map->map[x][y] = 'N';
			y++;
		}
		else
			ft_move_noblock(map, x, y);
	}
	else
		ft_move_noblock(map, x, y);
}

void	ft_move_enemy(t_map *map, int x, int y)
{
	if (map->pacman->x < x)
	{
		if (ft_can_enemy(map, x - 1, y) == 1)
		{
			ft_put_back_enemy(map, x, y);
			ft_new_i(map, x - 1, y, map->img->oran_up);
			map->map[x][y] = 'N';
			x--;
		}
		else
			ft_move_oran_y(map, x, y);
	}
	else if (map->pacman->x == x)
		ft_move_oran_y(map, x, y);
	else if (map->pacman->x > x)
	{
		if (ft_can_enemy(map, x + 1, y) == 1)
		{
			ft_put_back_enemy(map, x, y);
			ft_new_i(map, x + 1, y, map->img->oran_dw);
			map->map[x][y] = 'N';
			x++;
		}
		else
			ft_move_oran_y(map, x, y);
	}
}
