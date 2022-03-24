/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pink.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 06:20:00 by pcatapan          #+#    #+#             */
/*   Updated: 2022/03/24 07:21:11 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static void	ft_move_noblock(t_map *map)
{
	if (ft_can_enemy(map, map->pink->x - 1, map->pink->y) == 1)
	{
		ft_put_back_enemy(map, map->pink->x, map->pink->y);
		ft_new_i(map, map->pink->x - 1, map->pink->y, \
					map->img->pink_up);
		map->pink->x--;
	}
	if (ft_can_enemy(map, map->pink->x, map->pink->y + 1) == 1)
	{
		ft_put_back_enemy(map, map->pink->x, map->pink->y);
		ft_new_i(map, map->pink->x, map->pink->y + 1, map->img->pink_dx);
		map->pink->y++;
	}
}

void	ft_move_pink_y(t_map *map)
{
	if (map->pacman->y < map->pink->y)
	{
		if (ft_can_enemy(map, map->pink->x, map->pink->y - 1) == 1)
		{
			ft_put_back_enemy(map, map->pink->x, map->pink->y);
			ft_new_i(map, map->pink->x, map->pink->y - 1, map->img->pink_sx);
			map->pink->y--;
		}
		else
			ft_move_noblock(map);
	}
	else if (map->pacman->y > map->pink->y)
	{
		if (ft_can_enemy(map, map->pink->x, map->pink->y + 1) == 1)
		{
			ft_put_back_enemy(map, map->pink->x, map->pink->y);
			ft_new_i(map, map->pink->x, map->pink->y + 1, map->img->pink_dx);
			map->pink->y++;
		}
		else
			ft_move_noblock(map);
	}
	else
		ft_move_noblock(map);
}

void	ft_move_pink_x(t_map *map)
{
	if (map->pacman->x < map->pink->x)
	{
		if (ft_can_enemy(map, map->pink->x - 1, map->pink->y) == 1)
		{
			ft_put_back_enemy(map, map->pink->x, map->pink->y);
			ft_new_i(map, map->pink->x - 1, map->pink->y, map->img->pink_up);
			map->pink->x--;
		}
		else
			ft_move_pink_y(map);
	}
	else if (map->pacman->x == map->pink->x)
		ft_move_pink_y(map);
	else if (map->pacman->x > map->pink->x)
	{
		if (ft_can_enemy(map, map->pink->x + 1, map->pink->y) == 1)
		{
			ft_put_back_enemy(map, map->pink->x, map->pink->y);
			ft_new_i(map, map->pink->x + 1, map->pink->y, map->img->pink_dw);
			map->pink->x++;
		}
		else
			ft_move_pink_y(map);
	}
}

//Aspetta Irina
void	ft_animate_pink(t_map *map)
{
	if (map->frames % 2 == 0)
	{
		mlx_put_image_to_window(map->mlx_ptr, map->window, map->img->back_g, \
									map->pink->y * SIZE, map->pink->x * SIZE);
		mlx_put_image_to_window(map->mlx_ptr, map->window, \
				map->img->pink_dw, map->pink->y * SIZE, map->pink->x * SIZE);
	}
	ft_temp_animate();
	if (map->frames % 2 != 0)
	{
		mlx_put_image_to_window(map->mlx_ptr, map->window, map->img->back_g, \
								map->pink->y * SIZE, map->pink->x * SIZE);
		mlx_put_image_to_window(map->mlx_ptr, map->window, \
		map->img->pink_dw, map->pink->y * SIZE, map->pink->x * SIZE);
	}	
}

void	ft_fill_to_img_pink(t_img *img, void *mlx_ptr)
{
	img->pink_dw = mlx_xpm_file_to_image(mlx_ptr, PINK_DW_1, \
		&img->w, &img->h);
	img->pink_dx = mlx_xpm_file_to_image(mlx_ptr, PINK_DX_1, \
	&img->w, &img->h);
	img->pink_sx = mlx_xpm_file_to_image(mlx_ptr, PINK_SX_1, \
	&img->w, &img->h);
	img->pink_up = mlx_xpm_file_to_image(mlx_ptr, PINK_UP_1, \
	&img->w, &img->h);
}
