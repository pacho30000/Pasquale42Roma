/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 08:12:07 by pcatapan          #+#    #+#             */
/*   Updated: 2022/05/04 22:46:47 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	ft_search_collect(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	while (x < map->h)
	{
		y = 0;
		while (y < map->w)
		{
			if (map->map[x][y] == 'C')
				return (0);
			y++;
		}
		x++;
	}
	return (1);
}

void	ft_new_i(t_map *map, int x, int y, void *img)
{
	mlx_put_image_to_window(map->mlx_ptr, map->window, \
			map->img->back_g, y * SIZE, x * SIZE);
	mlx_put_image_to_window(map->mlx_ptr, map->window, \
			img, y * SIZE, x * SIZE);
}

int	ft_can_player(char c, t_map *map)
{
	if (c == 'E' && ft_search_collect(map) == 1)
		ft_game_over(map);
	if (c == '0' || c == '2' || c == 'C')
		return (1);
	if (c == 'N')
		ft_game_over(map);
	return (0);
}
