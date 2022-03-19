/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 00:32:18 by pcatapan          #+#    #+#             */
/*   Updated: 2022/03/19 07:56:31 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_put_img_norma(t_map *map, t_img *img, int x, int y)
{
	if (map->map[x][y] == 'C')
		mlx_put_image_to_window(map->mlx_ptr, map->window, \
								img->collezionabile, y * SIZE, x * SIZE);
	if (map->map[x][y] == 'E')
		mlx_put_image_to_window(map->mlx_ptr, map->window, \
								img->exit, y * SIZE, x * SIZE);
	if (map->map[x][y] == '0')
		mlx_put_image_to_window(map->mlx_ptr, map->window, \
									img->zero, y * SIZE, x * SIZE);
}

void	ft_put_img(t_map *map, t_img *img)
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
				mlx_put_image_to_window(map->mlx_ptr, map->window, \
										img->wall, y * SIZE, x * SIZE);
			if (map->map[x][y] == 'P')
			{
				mlx_put_image_to_window(map->mlx_ptr, map->window, \
									img->pacman_open_sx, y * SIZE, x * SIZE);
				map->pacman.x = x;
				map->pacman.y = y;
			}
			ft_put_img_norma(map, img, x, y);
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
	map->img->back_g = mlx_xpm_file_to_image(map->mlx_ptr, BACK_G, \
									&map->img->w, &map->img->h);
	map->img->wall = mlx_xpm_file_to_image(map->mlx_ptr, WALL, &map->img->w, \
											&map->img->h);
	map->img->zero = mlx_xpm_file_to_image(map->mlx_ptr, \
				ZERO, &map->img->w, &map->img->h);
	map->img->collezionabile = mlx_xpm_file_to_image(map->mlx_ptr, \
				COLLECT, &map->img->w, &map->img->h);
	map->img->exit = mlx_xpm_file_to_image(map->mlx_ptr, \
				EXIT, &map->img->w, &map->img->h);
	ft_put_img(map, map->img);
}
