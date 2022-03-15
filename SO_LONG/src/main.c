/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 19:59:37 by pcatapan          #+#    #+#             */
/*   Updated: 2022/03/15 21:45:02 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*
Il primo if controlla il numero di argomenti passati.
Il while fa avanzare l'indice del secondo argomento fino al punto,
	per poi controllare l'estensione con l'if.
Il terzo if controlla il contenuto della mappa, elabora la lunghezza (map.w),
	l'altezza (map.h) e salva tutta la mappa in una stringa (map.max_line).
*/
int	ft_checker(int argc, char **argv, t_map *map)
{
	int				i;
	t_control_obj	obj;

	i = 0;
	if (argc < 2)
	{
		ft_printf("\x1b[31m%s\n", "Invalid number of arguments!");
		return (0);
	}
	while (argv[1][i] != '.')
		i++;
	if (!(argv[1][i + 1] == 'b' && argv[1][i + 2] == 'e'
			&& argv[1][i + 3] == 'r'))
	{
		ft_printf("\x1b[31m%s\n", "Invalid exstension map!");
		return (0);
	}
	if (ft_checker_map(argv[1], map, &obj) == 0)
		return (0);
	ft_printf ("La matrice é larga : %d", map->w);
	ft_printf ("\nLa matrice é alta : %d", map->h);
	return (1);
}

int	main(int argc, char **argv)
{
	t_map	map;
	void	*mlx;
	void	*win_mlx;

	map.h = 0;
	if (ft_checker(argc, argv, &map) == 0)
		return (0);

	//ft_chack_map();
	//mlx = mlx_init();
	//win_mlx = mlx_new_window(mlx, 25 * 64, 12 * 64, "Prova");
	//mlx_loop(mlx);
}
