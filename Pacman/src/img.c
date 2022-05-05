/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 00:32:18 by pcatapan          #+#    #+#             */
/*   Updated: 2022/05/04 17:28:02 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// int	ft_put_img_enemy(t_map *map, int temp, int x, int y)
// {
// 	if (temp == 3)
// 	{
// 		mlx_put_image_to_window(map->mlx_ptr, map->window, \
// 								map->img->pink_dw, y * SIZE, x * SIZE);
// 		map->pink->x = x;
// 		map->pink->y = y;
// 	}
// 	if (temp == 2)
// 	{
// 		mlx_put_image_to_window(map->mlx_ptr, map->window, \
// 								map->img->oran_dw, y * SIZE, x * SIZE);
// 		map->oran->x = x;
// 		map->oran->y = y;
// 	}
// 	if (temp == 1)
// 	{
// 		mlx_put_image_to_window(map->mlx_ptr, map->window, \
// 								map->img->blu_dw, y * SIZE, x * SIZE);
// 		map->blu->x = x;
// 		map->blu->y = y;
// 	}
// 	return ((temp - 1));
// }

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

	x = -1;
	while (++x < map->h)
	{
		y = -1;
		while (y++ < map->w)
		{
			if (map->map[x][y] == 'N')
				mlx_put_image_to_window(map->mlx_ptr, map->window, \
							map->img->oran_dw, y * SIZE, x * SIZE);
			ft_put_img_norma(map, x, y);
		}
	}
}

void	ft_fill_to_img_orange(t_img *img, void *mlx_ptr)
{
	img->oran_dw = mlx_xpm_file_to_image(mlx_ptr, ORANGE_DW_1, \
		&img->w, &img->h);
	img->oran_dx = mlx_xpm_file_to_image(mlx_ptr, ORANGE_DX_1, \
	&img->w, &img->h);
	img->oran_sx = mlx_xpm_file_to_image(mlx_ptr, ORANGE_SX_1, \
	&img->w, &img->h);
	img->oran_up = mlx_xpm_file_to_image(mlx_ptr, ORANGE_UP_1, \
	&img->w, &img->h);
}

void	ft_img(t_map *map)
{
	map->img = malloc(sizeof(t_img));
	map->pacman = malloc(sizeof(t_sprite));
	map->oran = malloc(sizeof(t_sprite));
	ft_fill_to_img_orange(map->img, map->mlx_ptr);
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

// map->pink = malloc(sizeof(t_sprite));
// map->blu = malloc(sizeof(t_sprite));
//ft_fill_to_img_pink(map->img, map->mlx_ptr);
//ft_fill_to_img_blu(map->img, map->mlx_ptr);