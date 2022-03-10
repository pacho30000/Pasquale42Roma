/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 23:52:38 by pcatapan          #+#    #+#             */
/*   Updated: 2022/03/10 06:47:24 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_width_matrix(int fd, t_map *map)
{
	char	*save;
	char	*line;

	line = (char *)malloc(sizeof(char) * 1);
	save = (char *)malloc(sizeof(char) * 1);
	if (!save || !line)
		return (NULL);
	line[0] = '\0';
	save[0] = '\0';
	while (!ft_strchr(line, '\n') && map->read != 0)
	{
		map->read = read (fd, save, map->w);
		if (map->read == -1)
		{
			//free(save);
			//free(line);
			return (NULL);
		}
		save[map->read++] = '\0';
		line = ft_strjoin(line, save);
	}
	//free(save);
	map->w = ft_strlen(line);
	return (*(&line));
}

int	ft_hight_matrix(int fd, t_map *map)
{
	char	*line;

	map->h = 1;
	while (map->read != 0)
	{
		line = ft_width_matrix(fd, map);
		if (line[map->w - 1] == '\n' && line[map->w] == '\0')
			map->h++;
		else
			return (0);
	}
	return (1);
}

int	ft_checker_map(const char *file, t_map *map)
{
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("\x1b[31m%s\n", "Error when open the map!");
		return (0);
	}
	if (ft_width_matrix(fd, map) == NULL)
	{
		ft_printf("\x1b[31m%s\n", "Error with ft_width_matrix!");
		return (0);
	}
	map->read = 1;
	if (ft_hight_matrix(fd, map) == 0)
	{
		ft_printf("\x1b[31m%s\n", "Error with ft_hight_matrix!");
		return (0);
	}
	return (1);
}

int	ft_checker(int argc, char **argv, t_map *map)
{
	int	i;

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
	if (ft_checker_map(argv[1], map) == 0)
		return (0);
	ft_printf ("/n La matrice é larga : %n", map->w);
	ft_printf ("/n La matrice é alta : %n", map->h);
	return (1);
}
