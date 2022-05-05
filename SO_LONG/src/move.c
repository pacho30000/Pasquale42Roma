/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 06:38:52 by pcatapan          #+#    #+#             */
/*   Updated: 2022/05/05 18:56:27 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_put_number(t_map *map)
{
	char	*num;

	mlx_put_image_to_window(map->mlx_ptr, map->window, map->img->wall2, \
							0 * SIZE, 0 * SIZE);
	mlx_put_image_to_window(map->mlx_ptr, map->window, map->img->wall2, \
							1 * SIZE, 0 * SIZE);
	mlx_put_image_to_window(map->mlx_ptr, map->window, map->img->wall2, \
							2 * SIZE, 0 * SIZE);
	mlx_string_put(map->mlx_ptr, map->window, 2, 15, 0xFFFFFFFF, "MOVES :");
	num = ft_itoa(map->moves);
	mlx_string_put(map->mlx_ptr, map->window, 75, 15, 0xFFFFFFFF, num);
	free (num);
}

/*
Freccia UP(126) -- Freccia DW(125); 
Freccia DX(124) -- Freccia SX(123)
W(13) --- A(0) --- S(1) --- D(2)
ESC(53)--- Invio(36) --- Tab(49)
*/
int	ft_controll_key(int key, t_map *map)
{
	map->map[map->player->x][map->player->y] = '0';
	if (key == 13 || key == 126)
		ft_player_up(map);
	if (key == 125 || key == 1)
		ft_player_dw(map);
	if (key == 124 || key == 2)
		ft_player_dx(map);
	if (key == 123 || key == 0)
		ft_player_sx(map);
	ft_printf("MOVES : %d\n", map->moves);
	ft_put_number(map);
	if (key == 53)
		exit (0);
	return (0);
}

int	ft_loop(t_map *map)
{
	int	x;
	int	y;
	int	true;

	x = -1;
	true = 0;
	if (map->animate++ <= 3000)
		return (0);
	map->animate = 0;
	while (++x < map->h)
	{
		y = 0;
		while (y < map->w)
		{
			if (map->map[x][y] == 'C')
				true = 1;
			if (map->map[x][y] == 'N')
				ft_animate_enemy(map, x, y);
			y++;
		}
	}
	if (true == 0)
		ft_search_exit(map);
	map->t_img++;
	return (0);
}

void	ft_move(t_map *map)
{
	map->t_img = 0;
	map->moves = 0;
	map->animate = 0;
	mlx_hook(map->window, 2, 1L << 0, &ft_controll_key, map);
	mlx_hook(map->window, 17, 1L << 17, &ft_game_over, map);
	mlx_loop_hook(map->mlx_ptr, &ft_loop, map);
}
