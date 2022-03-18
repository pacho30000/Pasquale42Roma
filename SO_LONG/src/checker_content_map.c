/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_content_map.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanghel <aanghel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 21:53:16 by pcatapan          #+#    #+#             */
/*   Updated: 2022/03/17 02:10:10 by aanghel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_check_lateral_walls(t_map *map, int i, int k)
{
	int	j;

	j = 2;
	while (j <= map->h)
	{
		if (map->max_line[map->w * j - 2] != '1')
		{
			ft_printf("\x1b[31m%s\n", "The last colum isn't all walls!");
			return (0);
		}
		j++;
	}
	j = 1;
	while (j < map->h)
	{
		if (map->max_line[(k + 1) - (map->w * j)] != '1')
		{
			ft_printf("\x1b[31m%s\n", "The first colum isn't all walls!");
			return (0);
		}
		j++;
	}
	return (1);
}

int	ft_check_maps_walls(t_map *map)
{
	int	i;
	int	k;

	i = 0;
	while (map->max_line[i] != '\n')
	{
		if (map->max_line[i] != '1')
		{
			ft_printf("\x1b[31m%s\n", "The first row isn't all walls!");
			return (0);
		}
		i++;
	}
	k = map->w * map->h - 2;
	while (map->max_line[k] != '\n')
	{
		if (map->max_line[k] != '1')
			return (0);
		k--;
	}
	if (ft_check_lateral_walls(map, i, k) == 0)
		return (0);
	return (1);
}

int	ft_count_element(t_map *map, t_control_obj *obj)
{
	if (obj->player != 1)
	{
		ft_printf("\x1b[31m%s\n", "Too many players!");
		return (0);
	}
	if (obj->coin != 1)
	{
		ft_printf("\x1b[31m%s\n", "Too many collectible!");
		return (0);
	}
	if (obj->exit != 1)
	{
		ft_printf("\x1b[31m%s\n", "Too many exit!");
		return (0);
	}
	return (1);
}

int	ft_content_map(t_map *map, t_control_obj *obj)
{
	int	i;

	i = 0;
	obj->player = 0;
	obj->coin = 0;
	obj->exit = 0;
	while (map->max_line[i] != '\0')
	{
		if (map->max_line[i] == 'P')
			obj->player++;
		else if (map->max_line[i] == 'E')
			obj->exit++;
		else if (map->max_line[i] == 'C')
			obj->coin++;
		else if (!(map->max_line[i] == '1' || map->max_line[i] == '0'
				|| map->max_line[i] == '\n'))
		{
			ft_printf("\x1b[31m%s\n", "Error find a charter not permised!");
			return (0);
		}
		i++;
	}
	return (1);
}
