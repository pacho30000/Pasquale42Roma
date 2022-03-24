/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orange.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 06:18:44 by pcatapan          #+#    #+#             */
/*   Updated: 2022/03/24 07:14:55 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static void	ft_move_noblock(t_map *map)
{
	if (ft_can_enemy(map, map->oran->x - 1, map->oran->y) == 1)
	{
		ft_put_back_enemy(map, map->oran->x, map->oran->y);
		ft_new_i(map, map->oran->x - 1, map->oran->y, \
					map->img->oran_up);
		map->oran->x--;
	}
}

void	ft_move_orange_y(t_map *map)
{
	if (map->pacman->y > map->oran->y)
	{
		if (ft_can_enemy(map, map->oran->x, map->oran->y - 1) == 1)
		{
			ft_put_back_enemy(map, map->oran->x, map->oran->y);
			ft_new_i(map, map->oran->x, map->oran->y - 1, map->img->oran_sx);
			map->oran->y--;
		}
		else
			ft_move_noblock(map);
	}
	else if (map->pacman->y < map->oran->y)
	{
		if (ft_can_enemy(map, map->oran->x, map->oran->y + 1) == 1)
		{
			ft_put_back_enemy(map, map->oran->x, map->oran->y);
			ft_new_i(map, map->oran->x, map->oran->y + 1, map->img->oran_dx);
			map->oran->y++;
		}
		else
			ft_move_noblock(map);
	}
}

void	ft_move_orange_x(t_map *map)
{
	if (map->pacman->x > map->oran->x)
	{
		if (ft_can_enemy(map, map->oran->x - 1, map->oran->y) == 1)
		{
			ft_put_back_enemy(map, map->oran->x, map->oran->y);
			ft_new_i(map, map->oran->x - 1, map->oran->y, \
					map->img->oran_up);
			map->oran->x--;
		}
		else
			ft_move_orange_y(map);
	}
	else if (map->pacman->x == map->oran->x)
		ft_move_orange_y(map);
	else if (map->pacman->x < map->oran->x)
	{
		if (ft_can_enemy(map, map->oran->x + 1, map->oran->y) == 1)
		{
			ft_put_back_enemy(map, map->oran->x, map->oran->y);
			ft_new_i(map, map->oran->x + 1, map->oran->y, map->img->oran_dw);
			map->oran->x++;
		}
		else
			ft_move_orange_y(map);
	}
}

//Aspetta Irina
void	ft_animate_orange(t_map *map)
{
	if (map->frames % 2 == 0)
	{
		mlx_put_image_to_window(map->mlx_ptr, map->window, map->img->back_g, \
								map->oran->y * SIZE, map->oran->x * SIZE);
		mlx_put_image_to_window(map->mlx_ptr, map->window, \
		map->img->oran_dw, map->oran->y * SIZE, map->oran->x * SIZE);
	}
	ft_temp_animate();
	if (map->frames % 2 != 0)
	{
		mlx_put_image_to_window(map->mlx_ptr, map->window, map->img->back_g, \
								map->oran->y * SIZE, map->oran->x * SIZE);
		mlx_put_image_to_window(map->mlx_ptr, map->window, \
		map->img->oran_dw, map->oran->y * SIZE, map->oran->x * SIZE);
	}	
}

void	ft_fill_to_img_orange(t_img *img, void *mlx_ptr)
{
	img->oran_dw = mlx_xpm_file_to_image(mlx_ptr, ORANGE_DW_1, \
		&img->w, &img->h);
	img->oran_dx = mlx_xpm_file_to_image(mlx_ptr, ORANGE_DX_1, \
	&img->w, &img->h);
	img->oran_sx = mlx_xpm_file_to_image(mlx_ptr, ORANGE_SX_1, \
	&img->w, &img->h);
	img->oran_up = mlx_xpm_file_to_image(mlx_ptr, ORANGE_UP_1, \
	&img->w, &img->h);
}
