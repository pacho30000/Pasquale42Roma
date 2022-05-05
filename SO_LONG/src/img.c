/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 00:32:18 by pcatapan          #+#    #+#             */
/*   Updated: 2022/05/05 18:12:43 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_put_img_norma(t_map *map, int x, int y)
{
	mlx_put_image_to_window(map->mlx_ptr, map->window, \
								map->img->back_g, y * SIZE, x * SIZE);
	if (map->map[x][y] == 'C')
		mlx_put_image_to_window(map->mlx_ptr, map->window, \
								map->img->collezionabile, y * SIZE, x * SIZE);
	if (map->map[x][y] == 'E')
		mlx_put_image_to_window(map->mlx_ptr, map->window, \
								map->img->exit1, y * SIZE, x * SIZE);
	if (map->map[x][y] == '1')
		mlx_put_image_to_window(map->mlx_ptr, map->window, \
										map->img->wall, y * SIZE, x * SIZE);
	if (map->map[x][y] == 'P')
	{
		mlx_put_image_to_window(map->mlx_ptr, map->window, \
								map->img->player_r, y * SIZE, x * SIZE);
		map->player->x = x;
		map->player->y = y;
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
			ft_put_img_norma(map, x, y);
			if (map->map[x][y] == 'N')
				mlx_put_image_to_window(map->mlx_ptr, map->window, \
							img->enemy1, y * SIZE, x * SIZE);
		}
	}
}

void	ft_img(t_map *map)
{
	map->img = malloc(sizeof(t_img));
	map->player = malloc(sizeof(t_sprite));
	map->img->player_r = mlx_xpm_file_to_image(map->mlx_ptr, PLAYERSR, \
							&map->img->w, &map->img->h);
	map->img->player_l = mlx_xpm_file_to_image(map->mlx_ptr, PLAYERSL, \
							&map->img->w, &map->img->h);
	map->img->enemy1 = mlx_xpm_file_to_image(map->mlx_ptr, ENEMY1, \
							&map->img->w, &map->img->h);
	map->img->enemy2 = mlx_xpm_file_to_image(map->mlx_ptr, ENEMY2, \
							&map->img->w, &map->img->h);
	map->img->back_g = mlx_xpm_file_to_image(map->mlx_ptr, BACK_G, \
									&map->img->w, &map->img->h);
	map->img->wall = mlx_xpm_file_to_image(map->mlx_ptr, WALL, &map->img->w, \
											&map->img->h);
	map->img->wall2 = mlx_xpm_file_to_image(map->mlx_ptr, WALL2, &map->img->w, \
											&map->img->h);
	map->img->collezionabile = mlx_xpm_file_to_image(map->mlx_ptr, \
				COLLECT, &map->img->w, &map->img->h);
	map->img->exit1 = mlx_xpm_file_to_image(map->mlx_ptr, \
				EXIT1, &map->img->w, &map->img->h);
	map->img->exit2 = mlx_xpm_file_to_image(map->mlx_ptr, \
				EXIT2, &map->img->w, &map->img->h);
	ft_put_img(map, map->img);
}
