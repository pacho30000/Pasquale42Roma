/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_over.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 20:44:12 by pcatapan          #+#    #+#             */
/*   Updated: 2022/03/29 21:34:38 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_game_over(t_map *map)
{
	mlx_put_image_to_window(map->mlx_ptr, map->window, map->img->back_g, \
			map->pacman->y * SIZE, map->pacman->x * SIZE);
	mlx_put_image_to_window(map->mlx_ptr, map->window, map->img->pacman_close, \
			map->pacman->y * SIZE, map->pacman->x * SIZE);
	map->death = 1;
}
