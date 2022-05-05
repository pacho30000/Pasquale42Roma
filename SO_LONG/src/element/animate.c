/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 20:49:45 by pcatapan          #+#    #+#             */
/*   Updated: 2022/05/05 18:57:58 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	ft_animate_enemy(t_map *map, int x, int y)
{
	if (map->t_img % 2 == 0)
		ft_new_i(map, x, y, map->img->enemy1);
	else if (map->t_img % 2 != 0)
		ft_new_i(map, x, y, map->img->enemy2);
	if (map->t_img > 10000)
		map->t_img = 0;
}

void	ft_animate_exit(t_map *map, int x, int y)
{
	if (map->t_img % 2 == 0)
		ft_new_i(map, x, y, map->img->exit1);
	else if (map->t_img % 2 != 0)
		ft_new_i(map, x, y, map->img->exit2);
	if (map->t_img > 10000)
		map->t_img = 0;
}

void	ft_search_exit(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	while (x < map->h)
	{
		y = 0;
		while (y < map->w)
		{
			if (map->map[x][y] == 'E')
				ft_animate_exit(map, x, y);
			y++;
		}
		x++;
	}
}
