/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blu.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 06:22:00 by pcatapan          #+#    #+#             */
/*   Updated: 2022/03/21 20:11:42 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	ft_animate_blu(t_map *map)
{
	if (map->frames % 2 == 0)
	{
		mlx_put_image_to_window(map->mlx_ptr, map->window, map->img->back_g, \
									map->blu->y * SIZE, map->blu->x * SIZE);
		mlx_put_image_to_window(map->mlx_ptr, map->window, \
				map->img->blu_dw_1, map->blu->y * SIZE, map->blu->x * SIZE);
	}
	ft_temp_animate();
	if (map->frames % 2 != 0)
	{
		mlx_put_image_to_window(map->mlx_ptr, map->window, map->img->back_g, \
								map->blu->y * SIZE, map->blu->x * SIZE);
		mlx_put_image_to_window(map->mlx_ptr, map->window, \
		map->img->blu_dw_2, map->blu->y * SIZE, map->blu->x * SIZE);
	}	
}

void	ft_fill_to_img_blu(t_img *img, void *mlx_ptr)
{
	img->blu_dw_1 = mlx_xpm_file_to_image(mlx_ptr, BLU_DW_1, &img->w, &img->h);
	img->blu_dw_2 = mlx_xpm_file_to_image(mlx_ptr, BLU_DW_2, &img->w, &img->h);
	img->blu_dx_1 = mlx_xpm_file_to_image(mlx_ptr, BLU_DX_1, &img->w, &img->h);
	img->blu_dx_2 = mlx_xpm_file_to_image(mlx_ptr, BLU_DX_2, &img->w, &img->h);
	img->blu_sx_1 = mlx_xpm_file_to_image(mlx_ptr, BLU_SX_1, &img->w, &img->h);
	img->blu_sx_2 = mlx_xpm_file_to_image(mlx_ptr, BLU_SX_2, &img->w, &img->h);
	img->blu_up_1 = mlx_xpm_file_to_image(mlx_ptr, BLU_UP_1, &img->w, &img->h);
	img->blu_up_2 = mlx_xpm_file_to_image(mlx_ptr, BLU_UP_2, &img->w, &img->h);
}
