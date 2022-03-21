/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 23:01:58 by aanghel           #+#    #+#             */
/*   Updated: 2022/03/20 06:51:06 by pcatapan         ###   ########.fr       */
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
		while (y <= map->w)
		{
			if (map->max_line[s] != '\n')
				map->map[x][y] = map->max_line[s];
			else
				map->map[x][y] = '\0';
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
		while (map->map[i][j] != '\0')
		{
			ft_printf("%c", map->map[i][j]);
			j++;
		}
		if (map->map[i][j] == '\0')
			ft_printf("\n");
		i++;
	}
}

void	ft_creating_map(t_map *map)
{
	int	i;

	i = 0;
	map->w = map->w - 1;
	map->map = malloc(map->h * sizeof(char *));
	if (!map->map)
		return ;
	while (i < map->h)
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
	map->window = mlx_new_window(map->mlx_ptr, map->w * SIZE, \
					map->h * SIZE, "42 PacMan by Pcatapan");
	ft_img(map);
	return ;
}
