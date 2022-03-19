/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pacman.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 06:23:09 by pcatapan          #+#    #+#             */
/*   Updated: 2022/03/19 09:44:49 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	ft_pacman_dx(t_map *map)
{
	ft_chang_img_direction(map, map->pacman.x, map->pacman.y, \
							map->img->pacman_open_dx);
	while (map->map[map->pacman.x][map->pacman.y + 1] != '1')
	{
		mlx_put_image_to_window(map->mlx_ptr, map->window, \
	map->img->back_g, map->pacman.y * SIZE, map->pacman.x * SIZE);
		sleep(1);
		mlx_put_image_to_window(map->mlx_ptr, map->window, \
	map->img->back_g, (map->pacman.y + 1) * SIZE, map->pacman.x * SIZE);
		sleep(1);
		mlx_put_image_to_window(map->mlx_ptr, map->window, \
	map->img->pacman_open_dx, (map->pacman.y + 1) * SIZE, map->pacman.x * SIZE);
		sleep(1);
		map->pacman.y++;
	}
}

void	ft_pacman_sx(t_map *map)
{
	int	x;
	int	y;

	x = map->pacman.x;
	y = map->pacman.y;
	ft_chang_img_direction(map, x, y, map->img->pacman_open_sx);
}

void	ft_pacman_dw(t_map *map)
{
	int	x;
	int	y;

	x = map->pacman.x;
	y = map->pacman.y;
	ft_chang_img_direction(map, x, y, map->img->pacman_open_dw);
}

void	ft_pacman_up(t_map *map)
{
	int	x;
	int	y;

	x = map->pacman.x;
	y = map->pacman.y;
	ft_chang_img_direction(map, x, y, map->img->pacman_open_up);
}

void	ft_fill_to_img_pacman(t_img *img, void *mlx_ptr)
{
	img->pacman_close = mlx_xpm_file_to_image(mlx_ptr, PAC_CLOSE, \
	&img->w, &img->h);
	img->pacman_dw = mlx_xpm_file_to_image(mlx_ptr, PAC_DW, \
	&img->w, &img->h);
	img->pacman_dx = mlx_xpm_file_to_image(mlx_ptr, PAC_DX, \
	&img->w, &img->h);
	img->pacman_sx = mlx_xpm_file_to_image(mlx_ptr, PAC_SX, \
	&img->w, &img->h);
	img->pacman_up = mlx_xpm_file_to_image(mlx_ptr, PAC_UP, \
	&img->w, &img->h);
	img->pacman_open_dw = mlx_xpm_file_to_image(mlx_ptr, PAC_O_DW, \
	&img->w, &img->h);
	img->pacman_open_dx = mlx_xpm_file_to_image(mlx_ptr, PAC_O_DX, \
	&img->w, &img->h);
	img->pacman_open_sx = mlx_xpm_file_to_image(mlx_ptr, PAC_O_SX, \
	&img->w, &img->h);
	img->pacman_open_up = mlx_xpm_file_to_image(mlx_ptr, PAC_O_UP, \
	&img->w, &img->h);
}
