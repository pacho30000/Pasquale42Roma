/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pink.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 06:20:00 by pcatapan          #+#    #+#             */
/*   Updated: 2022/03/21 20:09:51 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	ft_animate_pink(t_map *map)
{
	if (map->frames % 2 == 0)
	{
		mlx_put_image_to_window(map->mlx_ptr, map->window, map->img->back_g, \
									map->pink->y * SIZE, map->pink->x * SIZE);
		mlx_put_image_to_window(map->mlx_ptr, map->window, \
				map->img->pink_dw_1, map->pink->y * SIZE, map->pink->x * SIZE);
	}
	ft_temp_animate();
	if (map->frames % 2 != 0)
	{
		mlx_put_image_to_window(map->mlx_ptr, map->window, map->img->back_g, \
								map->pink->y * SIZE, map->pink->x * SIZE);
		mlx_put_image_to_window(map->mlx_ptr, map->window, \
		map->img->pink_dw_2, map->pink->y * SIZE, map->pink->x * SIZE);
	}	
}

void	ft_fill_to_img_pink(t_img *img, void *mlx_ptr)
{
	img->pink_dw_1 = mlx_xpm_file_to_image(mlx_ptr, PINK_DW_1, \
		&img->w, &img->h);
	img->pink_dw_2 = mlx_xpm_file_to_image(mlx_ptr, PINK_DW_2, \
	&img->w, &img->h);
	img->pink_dx_1 = mlx_xpm_file_to_image(mlx_ptr, PINK_DX_1, \
	&img->w, &img->h);
	img->pink_dx_2 = mlx_xpm_file_to_image(mlx_ptr, PINK_DX_2, \
	&img->w, &img->h);
	img->pink_sx_1 = mlx_xpm_file_to_image(mlx_ptr, PINK_SX_1, \
	&img->w, &img->h);
	img->pink_sx_2 = mlx_xpm_file_to_image(mlx_ptr, PINK_SX_2, \
	&img->w, &img->h);
	img->pink_up_1 = mlx_xpm_file_to_image(mlx_ptr, PINK_UP_1, \
	&img->w, &img->h);
	img->pink_up_2 = mlx_xpm_file_to_image(mlx_ptr, PINK_UP_2, \
	&img->w, &img->h);
}
