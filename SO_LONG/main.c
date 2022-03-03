/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 19:59:37 by pcatapan          #+#    #+#             */
/*   Updated: 2022/03/03 20:03:31 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	void	*mlx;
	void	*win_mlx;

	mlx = mlx_init();
	win_mlx = mlx_new_window(mlx, 25 * 64, 12 * 64, "Prova");
	mlx_loop(mlx);
}
