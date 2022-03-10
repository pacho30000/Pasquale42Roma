/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 19:59:37 by pcatapan          #+#    #+#             */
/*   Updated: 2022/03/10 06:05:44 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int argc, char **argv)
{
	t_map	map;
	void	*mlx;
	void	*win_mlx;

	map.w = 1;
	map.read = 1;
	if (ft_checker(argc, argv, &map) == 0)
		return (0);
	//ft_chack_map();
	//mlx = mlx_init();
	//win_mlx = mlx_new_window(mlx, 25 * 64, 12 * 64, "Prova");
	//mlx_loop(mlx);
}
