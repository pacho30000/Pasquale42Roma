/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 03:20:38 by pcatapan          #+#    #+#             */
/*   Updated: 2022/03/24 07:07:41 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static void	ft_move_noblock(t_map *map)
{
	if (ft_can_enemy(map, map->red->x - 1, map->red->y) == 1)
	{
		ft_put_back_enemy(map, map->red->x, map->red->y);
		ft_new_i(map, map->red->x - 1, map->red->y, \
					map->img->red_up);
		map->red->x--;
	}
}

void	ft_move_red_y(t_map *map)
{
	if (map->pacman->y > map->red->y)
	{
		if (ft_can_enemy(map, map->red->x, map->red->y - 1) == 1)
		{
			ft_put_back_enemy(map, map->red->x, map->red->y);
			ft_new_i(map, map->red->x, map->red->y - 1, \
					map->img->red_sx);
			map->red->y--;
		}
		else
			ft_move_noblock(map);
	}
	else if (map->pacman->y < map->red->y)
	{
		if (ft_can_enemy(map, map->red->x, map->red->y + 1) == 1)
		{
			ft_put_back_enemy(map, map->red->x, map->red->y);
			ft_new_i(map, map->red->x, map->red->y + 1, map->img->red_dx);
			map->red->y++;
		}
		else
			ft_move_noblock(map);
	}
}

void	ft_move_red_x(t_map *map)
{
	if (map->pacman->x > map->red->x)
	{
		if (ft_can_enemy(map, map->red->x - 1, map->red->y) == 1)
		{
			ft_put_back_enemy(map, map->red->x, map->red->y);
			ft_new_i(map, map->red->x - 1, map->red->y, map->img->red_up);
			map->red->x--;
		}
		else
			ft_move_red_y(map);
	}
	else if (map->pacman->x == map->red->x)
		ft_move_red_y(map);
	else if (map->pacman->x < map->red->x)
	{
		if (ft_can_enemy(map, map->red->x + 1, map->red->y) == 1)
		{
			ft_put_back_enemy(map, map->red->x, map->red->y);
			ft_new_i(map, map->red->x + 1, map->red->y, map->img->red_dw);
			map->red->x++;
		}
		else
			ft_move_red_y(map);
	}
}

//  Va modificata aspetta Irina --Solo i piedi
void	ft_animate_red(t_map *map)
{
	if (map->frames % 2 == 0)
	{
		mlx_put_image_to_window(map->mlx_ptr, map->window, map->img->back_g, \
									map->red->y * SIZE, map->red->x * SIZE);
		mlx_put_image_to_window(map->mlx_ptr, map->window, map->img->red_dw, \
								map->red->y * SIZE, map->red->x * SIZE);
	}
	ft_temp_animate();
	if (map->frames % 2 != 0)
	{
		mlx_put_image_to_window(map->mlx_ptr, map->window, map->img->back_g, \
								map->red->y * SIZE, map->red->x * SIZE);
		mlx_put_image_to_window(map->mlx_ptr, map->window, map->img->red_dw, \
								map->red->y * SIZE, map->red->x * SIZE);
	}
}

void	ft_fill_to_img_red(t_img *img, void *mlx_ptr)
{
	img->red_dw = mlx_xpm_file_to_image(mlx_ptr, RED_DW_1, &img->w, &img->h);
	img->red_dx = mlx_xpm_file_to_image(mlx_ptr, RED_DX_1, &img->w, &img->h);
	img->red_sx = mlx_xpm_file_to_image(mlx_ptr, RED_SX_1, &img->w, &img->h);
	img->red_up = mlx_xpm_file_to_image(mlx_ptr, RED_UP_1, &img->w, &img->h);
}
