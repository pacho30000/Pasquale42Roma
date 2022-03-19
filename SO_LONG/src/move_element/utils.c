/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 08:12:07 by pcatapan          #+#    #+#             */
/*   Updated: 2022/03/19 09:33:39 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	ft_chang_img_direction(t_map *map, int x, int y, void *img)
{
	mlx_put_image_to_window(map->mlx_ptr, map->window, \
							map->img->back_g, y * SIZE, x * SIZE);
	mlx_put_image_to_window(map->mlx_ptr, map->window, img, y * SIZE, \
								x * SIZE);
}
