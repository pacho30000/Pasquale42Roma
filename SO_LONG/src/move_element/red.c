/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 03:20:38 by pcatapan          #+#    #+#             */
/*   Updated: 2022/03/20 18:03:03 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	ft_animate_fix_red(t_map *map, int i)
{
	static int	g;

	g = 1;
	while (i < (2000001 * 100))
	{
		if (i == (200000 / 4) && g == 1)
		{
			g = 0;
			mlx_put_image_to_window(map->mlx_ptr, map->window, \
				map->img->back_g, map->red.y * SIZE, map->red.x * SIZE);
			mlx_put_image_to_window(map->mlx_ptr, map->window, \
				map->img->red_dw_2, map->red.y * SIZE, map->red.x * SIZE);
			mlx_put_image_to_window(map->mlx_ptr, map->window, \
				map->img->back_g, map->red.y * SIZE, map->red.x * SIZE);
		}
		else if (i == (200000 * 100) && g == 0)
		{
			g = 1;
			mlx_put_image_to_window(map->mlx_ptr, map->window, \
				map->img->back_g, map->red.y * SIZE, map->red.x * SIZE);
			mlx_put_image_to_window(map->mlx_ptr, map->window, \
				map->img->red_dw_1, map->red.y * SIZE, map->red.x * SIZE);
			mlx_put_image_to_window(map->mlx_ptr, map->window, \
				map->img->back_g, map->red.y * SIZE, map->red.x * SIZE);
		}
		i++;
	}
	i = 0;
}

void	ft_fill_list(t_map *map, t_img *img)
{
	map->red->img = (t_animate *)malloc(sizeof(t_animate));
	map->red->img->direction = UP;
	map->red->img->img = img->red_up_1;
	map->red->img->prev = NULL;
	map->red->img->next = img->red_up_2;
	map->red->img = map->red->img->next;
	map->red->img->direction = UP;
	map->red->img->img = img->red_up_2;
	map->red->img->prev = img->red_up_1;
	map->red->img->next = NULL;
}

void	ft_fill_to_img_red(t_img *img, void *mlx_ptr)
{
	img->red_dw_1 = mlx_xpm_file_to_image(mlx_ptr, RED_DW_1, &img->w, &img->h);
	img->red_dw_2 = mlx_xpm_file_to_image(mlx_ptr, RED_DW_2, &img->w, &img->h);
	img->red_dx_1 = mlx_xpm_file_to_image(mlx_ptr, RED_DX_1, &img->w, &img->h);
	img->red_dx_2 = mlx_xpm_file_to_image(mlx_ptr, RED_DX_2, &img->w, &img->h);
	img->red_sx_1 = mlx_xpm_file_to_image(mlx_ptr, RED_SX_1, &img->w, &img->h);
	img->red_sx_2 = mlx_xpm_file_to_image(mlx_ptr, RED_SX_2, &img->w, &img->h);
	img->red_up_1 = mlx_xpm_file_to_image(mlx_ptr, RED_UP_1, &img->w, &img->h);
	img->red_up_2 = mlx_xpm_file_to_image(mlx_ptr, RED_UP_2, &img->w, &img->h);
}
