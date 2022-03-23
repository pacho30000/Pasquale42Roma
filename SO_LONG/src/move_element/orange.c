/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orange.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 06:18:44 by pcatapan          #+#    #+#             */
/*   Updated: 2022/03/23 04:48:38 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

//Aspetta Irina
void	ft_animate_orange(t_map *map)
{
	if (map->frames % 2 == 0)
	{
		mlx_put_image_to_window(map->mlx_ptr, map->window, map->img->back_g, \
								map->orange->y * SIZE, map->orange->x * SIZE);
		mlx_put_image_to_window(map->mlx_ptr, map->window, \
		map->img->orange_dw, map->orange->y * SIZE, map->orange->x * SIZE);
	}
	ft_temp_animate();
	if (map->frames % 2 != 0)
	{
		mlx_put_image_to_window(map->mlx_ptr, map->window, map->img->back_g, \
								map->orange->y * SIZE, map->orange->x * SIZE);
		mlx_put_image_to_window(map->mlx_ptr, map->window, \
		map->img->orange_dw, map->orange->y * SIZE, map->orange->x * SIZE);
	}	
}

void	ft_fill_to_img_orange(t_img *img, void *mlx_ptr)
{
	img->orange_dw = mlx_xpm_file_to_image(mlx_ptr, ORANGE_DW_1, \
		&img->w, &img->h);
	img->orange_dx = mlx_xpm_file_to_image(mlx_ptr, ORANGE_DX_1, \
	&img->w, &img->h);
	img->orange_sx = mlx_xpm_file_to_image(mlx_ptr, ORANGE_SX_1, \
	&img->w, &img->h);
	img->orange_up = mlx_xpm_file_to_image(mlx_ptr, ORANGE_UP_1, \
	&img->w, &img->h);
}
