/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 00:32:18 by pcatapan          #+#    #+#             */
/*   Updated: 2022/03/20 18:05:15 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_put_img_enemy(t_map *map, int temp, int x, int y)
{
	if (temp == 4)
	{
		mlx_put_image_to_window(map->mlx_ptr, map->window, \
								map->img->pink_dw_1, y * SIZE, x * SIZE);
		map->pink->x = x;
		map->pink->y = y;
	}
	if (temp == 3)
	{
		mlx_put_image_to_window(map->mlx_ptr, map->window, \
								map->img->orange_dw_1, y * SIZE, x * SIZE);
		map->orange->x = x;
		map->orange->y = y;
	}
	if (temp == 2)
	{
		mlx_put_image_to_window(map->mlx_ptr, map->window, \
								map->img->blu_dw_1, y * SIZE, x * SIZE);
		map->blu->x = x;
		map->blu->y = y;
	}
	temp--;
	return (temp);
}

void	ft_put_img_norma(t_map *map, int x, int y)
{
	if (map->map[x][y] == 'C')
		mlx_put_image_to_window(map->mlx_ptr, map->window, \
								map->img->collezionabile, y * SIZE, x * SIZE);
	if (map->map[x][y] == 'E')
		mlx_put_image_to_window(map->mlx_ptr, map->window, \
								map->img->exit, y * SIZE, x * SIZE);
	if (map->map[x][y] == '0')
		mlx_put_image_to_window(map->mlx_ptr, map->window, \
									map->img->zero, y * SIZE, x * SIZE);
	if (map->map[x][y] == '1')
		mlx_put_image_to_window(map->mlx_ptr, map->window, \
										map->img->wall, y * SIZE, x * SIZE);
	if (map->map[x][y] == 'P')
	{
		mlx_put_image_to_window(map->mlx_ptr, map->window, \
								map->img->pacman_open_sx, y * SIZE, x * SIZE);
		map->pacman->x = x;
		map->pacman->y = y;
	}
}

void	ft_put_img(t_map *map, t_img *img)
{
	int	x;
	int	y;
	int	temp;

	x = -1;
	temp = map->object->enemy;
	while (++x < map->h)
	{
		y = -1;
		while (y++ < map->w)
		{
			if (map->map[x][y] == 'N')
			{
				if (temp == 1)
				{
					mlx_put_image_to_window(map->mlx_ptr, map->window, \
										map->img->red_dw_1, y * SIZE, x * SIZE);
					map->red->x = x;
					map->red->y = y;
				}
				temp = ft_put_img_enemy(map, temp, x, y);
			}
			ft_put_img_norma(map, x, y);
		}
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
	ft_fill_list(map, map->img);
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
