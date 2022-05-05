/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 06:23:09 by pcatapan          #+#    #+#             */
/*   Updated: 2022/05/05 17:40:23 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	ft_player_dx(t_map *map)
{
	if (ft_can_player(map->map[map->player->x][map->player->y + 1], map) == \
		1)
	{
		map->map[map->player->x][map->player->y] = '0';
		mlx_put_image_to_window(map->mlx_ptr, map->window, \
		map->img->back_g, map->player->y * SIZE, map->player->x * SIZE);
		ft_new_i(map, map->player->x, map->player->y + 1, \
						map->img->player_r);
		map->player->y++;
	}
	map->map[map->player->x][map->player->y] = 'P';
	map->moves++;
}

void	ft_player_sx(t_map *map)
{
	if (ft_can_player(map->map[map->player->x][map->player->y - 1], map) == \
		1)
	{
		map->map[map->player->x][map->player->y] = '0';
		mlx_put_image_to_window(map->mlx_ptr, map->window, \
	map->img->back_g, map->player->y * SIZE, map->player->x * SIZE);
		ft_new_i(map, map->player->x, map->player->y - 1, \
						map->img->player_l);
		map->player->y--;
	}
	map->map[map->player->x][map->player->y] = 'P';
	map->moves++;
}

void	ft_player_dw(t_map *map)
{
	if (ft_can_player(map->map[map->player->x + 1][map->player->y], map) == \
		1)
	{
		map->map[map->player->x][map->player->y] = '0';
		mlx_put_image_to_window(map->mlx_ptr, map->window, \
		map->img->back_g, map->player->y * SIZE, map->player->x * SIZE);
		ft_new_i(map, map->player->x + 1, map->player->y, \
						map->img->player_r);
		map->player->x++;
	}
	map->map[map->player->x][map->player->y] = 'P';
	map->moves++;
}

void	ft_player_up(t_map *map)
{
	if (ft_can_player(map->map[map->player->x - 1][map->player->y], map) == 1)
	{
		map->map[map->player->x][map->player->y] = '0';
		mlx_put_image_to_window(map->mlx_ptr, map->window, \
		map->img->back_g, map->player->y * SIZE, map->player->x * SIZE);
		ft_new_i(map, map->player->x - 1, map->player->y, \
						map->img->player_l);
		map->player->x--;
	}
	map->map[map->player->x][map->player->y] = 'P';
	map->moves++;
}
