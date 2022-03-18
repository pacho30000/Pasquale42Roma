/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 00:32:18 by pcatapan          #+#    #+#             */
/*   Updated: 2022/03/18 07:16:45 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_put_img(t_map *map, void *img_ptr)
{
	int	x;
	int	y;

	x = 0;
	while (x < map->h)
	{
		y = 0;
		while (y < map->w)
		{
			if (map->map[x][y] == '1')
			{
				mlx_put_image_to_window(map->mlx_ptr, map->window, img_ptr, \
											y * 48, x * 48);
			}
			y++;
		}
		x++;
	}
}

void	ft_img(t_map *map)
{
	map->img = malloc(sizeof(t_img));
	ft_fill_to_img_red(map->img, map->mlx_ptr);
	ft_fill_to_img_orange(map->img, map->mlx_ptr);
	ft_fill_to_img_pink(map->img, map->mlx_ptr);
	ft_fill_to_img_blu(map->img, map->mlx_ptr);
	ft_fill_to_img_pacman(map->img, map->mlx_ptr);
	ft_fill_to_img_walls(map->img, map->mlx_ptr);
	ft_put_img(map, map->img->blu_dw_1);
}
