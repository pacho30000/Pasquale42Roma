/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 19:59:37 by pcatapan          #+#    #+#             */
/*   Updated: 2022/03/09 07:59:31 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	int		i;
	void	*mlx;
	void	*win_mlx;

	if (argc < 2)
		ft_printf("\x1b[31m%s\n", "Invalid number of arguments!");
	while (argv[1][i] != '.')
		i++;
	if (!(argv[1][i + 1] == 'b' && argv[1][i +  2] == 'e' && argv[1][i +  3] == 'r'))
		ft_printf("\x1b[31m%s\n", "Invalid exstension map!");
	//ft_chack_map();
	//mlx = mlx_init();
	//win_mlx = mlx_new_window(mlx, 25 * 64, 12 * 64, "Prova");
	//mlx_loop(mlx);
}
