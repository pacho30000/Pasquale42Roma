/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orange.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 06:18:44 by pcatapan          #+#    #+#             */
/*   Updated: 2022/03/29 20:41:05 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	ft_move_oran_sx(t_map *map)
{
	if (ft_can_enemy(map, map->oran->x, map->oran->y - 1) == 1)
	{
		ft_put_back_enemy(map, map->oran->x, map->oran->y);
		ft_new_i(map, map->oran->x, map->oran->y - 1, map->img->oran_sx);
		map->oran->y--;
		map->oran->dir = -2;
	}
	else if (ft_can_enemy(map, map->oran->x - 1, map->oran->y) == 1)
	{
		ft_put_back_enemy(map, map->oran->x, map->oran->y);
		ft_new_i(map, map->oran->x - 1, map->oran->y, map->img->oran_up);
		map->oran->x--;
		map->oran->dir = -1;
	}
	else
		map->oran->dir = 0;
}

void	ft_move_oran_dx(t_map *map)
{
	if (ft_can_enemy(map, map->oran->x, map->oran->y + 1) == 1)
	{
		ft_put_back_enemy(map, map->oran->x, map->oran->y);
		ft_new_i(map, map->oran->x, map->oran->y + 1, map->img->oran_dx);
		map->oran->y++;
		map->oran->dir = 2;
	}
	else if (ft_can_enemy(map, map->oran->x + 1, map->oran->y) == 1)
	{
		ft_put_back_enemy(map, map->oran->x, map->oran->y);
		ft_new_i(map, map->oran->x + 1, map->oran->y, map->img->oran_dw);
		map->oran->x++;
		map->oran->dir = +1;
	}
	else
		map->oran->dir = 0;
}

void	ft_move_oran_dw(t_map *map)
{
	if (ft_can_enemy(map, map->oran->x + 1, map->oran->y) == 1)
	{
		ft_put_back_enemy(map, map->oran->x, map->oran->y);
		ft_new_i(map, map->oran->x + 1, map->oran->y, map->img->oran_dw);
		map->oran->x++;
		map->oran->dir = +1;
	}
	else if (ft_can_enemy(map, map->oran->x, map->oran->y + 1) == 1)
	{
		ft_put_back_enemy(map, map->oran->x, map->oran->y);
		ft_new_i(map, map->oran->x, map->oran->y + 1, map->img->oran_dx);
		map->oran->y++;
		map->oran->dir = 2;
	}
	else
		map->oran->dir = 0;
}

void	ft_move_oran_up(t_map *map)
{
	if (ft_can_enemy(map, map->oran->x - 1, map->oran->y) == 1)
	{
		ft_put_back_enemy(map, map->oran->x, map->oran->y);
		ft_new_i(map, map->oran->x - 1, map->oran->y, map->img->oran_up);
		map->oran->x--;
		map->oran->dir = -1;
	}
	else if (ft_can_enemy(map, map->oran->x, map->oran->y + 1) == 1)
	{
		ft_put_back_enemy(map, map->oran->x, map->oran->y);
		ft_new_i(map, map->oran->x, map->oran->y + 1, map->img->oran_dx);
		map->oran->y++;
		map->oran->dir = 2;
	}
	else
		map->oran->dir = 0;
}

void	ft_move_oran(t_map *map)
{
	if (map->oran->dir != 0)
	{
		if (map->oran->dir == -1)
			ft_move_oran_up(map);
		else if (map->oran->dir == +1)
			ft_move_oran_dw(map);
		else if (map->oran->dir == 2)
			ft_move_oran_dx(map);
		else if (map->oran->dir == -2)
			ft_move_oran_sx(map);
	}
	else if (map->pacman->x < map->oran->x)
		ft_move_oran_up(map);
	else if (map->pacman->y < map->oran->y)
		ft_move_oran_sx(map);
	else if (map->pacman->x > map->oran->x)
		ft_move_oran_dw(map);
	else if (map->pacman->y > map->oran->y)
		ft_move_oran_dx(map);
}
