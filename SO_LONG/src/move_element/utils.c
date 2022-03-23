/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 08:12:07 by pcatapan          #+#    #+#             */
/*   Updated: 2022/03/23 05:03:01 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	ft_put_back_enemy(t_map *map, int x, int y)
{
	if (map->map[x][y] == '2')
	{
		mlx_put_image_to_window(map->mlx_ptr, map->window, \
					map->img->back_g, y * SIZE, x * SIZE);
		map->map[x][y] = '2';
	}
	else
	{
		mlx_put_image_to_window(map->mlx_ptr, map->window, \
					map->img->back_g, y * SIZE, x * SIZE);
		mlx_put_image_to_window(map->mlx_ptr, map->window, \
					map->img->zero, y * SIZE, x * SIZE);
		map->map[x][y] = '0';
	}
}

void	ft_put_new_i(t_map *map, int x, int y, void *img)
{
	mlx_put_image_to_window(map->mlx_ptr, map->window, \
			map->img->back_g, y * SIZE, x * SIZE);
	mlx_put_image_to_window(map->mlx_ptr, map->window, \
			img, y * SIZE, x * SIZE);
}

void	ft_temp_animate(void)
{
	int	i;

	i = 0;
	while (i <= 20000000)
		i++;
	i = 0;
}

int	ft_can_move(char c)
{
	int		i;
	char	*elm;

	i = 0;
	if (!c)
	{
		ft_printf("Il valore di cconfronto non esiste\n");
		return (0);
	}
	elm = (char *)malloc(sizeof(char) * 3 + 1);
	elm[0] = '1';
	elm[1] = 'N';
	elm[2] = 'E';
	elm[3] = '\0';
	while (elm[i] != '\0')
	{
		if (elm[i] == c)
		{
			free(elm);
			return (0);
		}
		i++;
	}
	free(elm);
	return (1);
}
