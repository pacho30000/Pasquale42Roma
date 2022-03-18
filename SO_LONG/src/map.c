/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 23:01:58 by aanghel           #+#    #+#             */
/*   Updated: 2022/03/18 05:19:33 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_fill_matrix(t_map *map)
{
	int	x;
	int	s;
	int	y;

	x = 0;
	y = 0;
	s = 0;
	while (x < map->h)
	{
		y = 0;
		while (y < map->w)
		{
			map->map[x][y] = map->max_line[s];
			s++;
			y++;
		}
		x++;
	}
	free(map->max_line);
}

void	ft_print_map_in_shell(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->h)
	{
		j = 0;
		while (j < map->w)
		{
			ft_printf("%c", map->map[i][j]);
			j++;
		}
		i++;
	}
}

void	ft_creating_map(t_map *map)
{
	int	i;

	i = 0;
	map->map = (char **)malloc(sizeof(char) * map->h * map->w);
	if (!map->map)
		return ;
	while (i <= map->h)
	{
		map->map[i] = (char *)malloc(sizeof(char) * map->w);
		if (!map->map[i])
		{
			free(map->map);
			return ;
		}
		i++;
	}
	ft_fill_matrix(map);
	ft_print_map_in_shell(map);
	map->mlx_ptr = mlx_init();
	map->window = mlx_new_window(map->mlx_ptr, (map->w - 1) * SIZE, \
					map->h * SIZE, "42 PacMan by Pcatapan");
	ft_img(map);
}
