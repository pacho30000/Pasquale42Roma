/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 23:52:38 by pcatapan          #+#    #+#             */
/*   Updated: 2022/03/24 07:01:10 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_get_next_line(int fd)
{
	int		result;
	char	*save;
	char	*max_line;

	result = 1;
	save = (char *)malloc((sizeof(char)) * 1);
	max_line = (char *)malloc(sizeof(char) * 1);
	if (!save || !max_line)
		return (NULL);
	max_line[0] = '\0';
	while (result != 0)
	{
		result = read(fd, save, 1);
		if (result == -1)
		{
			free(save);
			free(max_line);
			return (NULL);
		}
		save[result] = '\0';
		max_line = ft_strjoin(max_line, save);
	}
	free(save);
	return (max_line);
}

int	ft_hight_matrix(t_map *map, char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		i++;
		if (line[i] == '\n')
		{
			map->h++;
			i++;
			if (i != map->h * map->w)
			{
				ft_printf("%s\n", "ERROR: The map is not rettangular.");
				return (0);
			}
		}
	}
	return (1);
}

int	ft_width_matrix(int file, t_map *map)
{
	int		i;

	i = 0;
	map->max_line = ft_get_next_line(file);
	if (map->max_line == NULL || map->max_line[0] == '\n')
		return (1);
	map->w = find_newline(map->max_line);
	if (ft_hight_matrix(map, map->max_line) == 0)
	{
		ft_printf("\x1b[31m%s\n", "ERROR: with ft_heigth_matrix!");
		free(map->max_line);
		return (0);
	}
	return (1);
}

int	ft_checker_map(const char *file, t_map *map, t_control_obj *obj)
{
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("\x1b[31m%s\n", "ERROR: when open the map!");
		close (fd);
		return (0);
	}
	if (ft_width_matrix(fd, map) == 0)
	{
		close (fd);
		return (0);
	}
	close (fd);
	if (ft_content_map(map, obj) == 0 || ft_count_element(map, obj) == 0
		|| ft_check_maps_walls(map) == 0)
	{
		ft_printf("\x1b[31m%s\n", "ERROR!\n");
		free (map->max_line);
		return (0);
	}
	return (1);
}
