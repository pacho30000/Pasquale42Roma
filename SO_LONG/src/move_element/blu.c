/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blu.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 06:22:00 by pcatapan          #+#    #+#             */
/*   Updated: 2022/03/24 07:30:58 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static void	ft_move_noblock(t_map *map)
{
	if (ft_can_enemy(map, map->blu->x - 1, map->blu->y) == 1)
	{
		ft_put_back_enemy(map, map->blu->x, map->blu->y);
		ft_new_i(map, map->blu->x - 1, map->blu->y, \
					map->img->blu_up);
		map->blu->x--;
	}
	if (ft_can_enemy(map, map->blu->x, map->blu->y + 1) == 1)
	{
		ft_put_back_enemy(map, map->blu->x, map->blu->y);
		ft_new_i(map, map->blu->x, map->blu->y + 1, map->img->blu_dx);
		map->blu->y++;
	}
}

void	ft_move_blu_y(t_map *map)
{
	if (map->pacman->y + 1 < map->blu->y)
	{
		if (ft_can_enemy(map, map->blu->x, map->blu->y - 1) == 1)
		{
			ft_put_back_enemy(map, map->blu->x, map->blu->y);
			ft_new_i(map, map->blu->x, map->blu->y - 1, map->img->blu_sx);
			map->blu->y--;
		}
		else
			ft_move_noblock(map);
	}
	else if (map->pacman->y + 1 > map->blu->y)
	{
		if (ft_can_enemy(map, map->blu->x, map->blu->y + 1) == 1)
		{
			ft_put_back_enemy(map, map->blu->x, map->blu->y);
			ft_new_i(map, map->blu->x, map->blu->y + 1, map->img->blu_dx);
			map->blu->y++;
		}
		else
			ft_move_noblock(map);
	}
	else
		ft_move_noblock(map);
}

void	ft_move_blu_x(t_map *map)
{
	if (map->pacman->x + 1 < map->blu->x)
	{
		if (ft_can_enemy(map, map->blu->x - 1, map->blu->y) == 1)
		{
			ft_put_back_enemy(map, map->blu->x, map->blu->y);
			ft_new_i(map, map->blu->x - 1, map->blu->y, map->img->blu_up);
			map->blu->x--;
		}
		else
			ft_move_blu_y(map);
	}
	else if (map->pacman->x == map->blu->x)
		ft_move_blu_y(map);
	else if (map->pacman->x + 1 > map->blu->x)
	{
		if (ft_can_enemy(map, map->blu->x + 1, map->blu->y) == 1)
		{
			ft_put_back_enemy(map, map->blu->x, map->blu->y);
			ft_new_i(map, map->blu->x + 1, map->blu->y, map->img->blu_dw);
			map->blu->x++;
		}
		else
			ft_move_blu_y(map);
	}
}

//Aspetta Irina
void	ft_animate_blu(t_map *map)
{
	if (map->frames % 2 == 0)
	{
		mlx_put_image_to_window(map->mlx_ptr, map->window, map->img->back_g, \
									map->blu->y * SIZE, map->blu->x * SIZE);
		mlx_put_image_to_window(map->mlx_ptr, map->window, \
				map->img->blu_dw, map->blu->y * SIZE, map->blu->x * SIZE);
	}
	ft_temp_animate();
	if (map->frames % 2 != 0)
	{
		mlx_put_image_to_window(map->mlx_ptr, map->window, map->img->back_g, \
								map->blu->y * SIZE, map->blu->x * SIZE);
		mlx_put_image_to_window(map->mlx_ptr, map->window, \
		map->img->blu_dw, map->blu->y * SIZE, map->blu->x * SIZE);
	}	
}

void	ft_fill_to_img_blu(t_img *img, void *mlx_ptr)
{
	img->blu_dw = mlx_xpm_file_to_image(mlx_ptr, BLU_DW_1, &img->w, &img->h);
	img->blu_dx = mlx_xpm_file_to_image(mlx_ptr, BLU_DX_1, &img->w, &img->h);
	img->blu_sx = mlx_xpm_file_to_image(mlx_ptr, BLU_SX_1, &img->w, &img->h);
	img->blu_up = mlx_xpm_file_to_image(mlx_ptr, BLU_UP_1, &img->w, &img->h);
}
