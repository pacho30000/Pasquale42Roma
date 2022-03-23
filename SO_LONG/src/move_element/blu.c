/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blu.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 06:22:00 by pcatapan          #+#    #+#             */
/*   Updated: 2022/03/23 04:48:26 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

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
