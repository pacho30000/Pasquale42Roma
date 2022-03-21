/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_contenet_map.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 21:53:16 by pcatapan          #+#    #+#             */
/*   Updated: 2022/03/15 21:55:47 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_contenet_map(t_map *map, t_control_obj *obj)
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
		else if (!(map->max_line[i] == '1' || map->max_line[i] == '0'))
		{
			free (map->max_line);
			ft_printf("\x1b[31m%s\n", "Error find a charter not permised!");
			return (0);
		}
		i++;
	}
	return (1);
}