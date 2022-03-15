/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 19:54:09 by pcatapan          #+#    #+#             */
/*   Updated: 2022/03/15 21:56:11 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./minilibx/mlx.h"
# include "./PRINTF/ft_printf.h"
# include <unistd.h>
# include <fcntl.h>

typedef int t_bool;
# define TRUE 1
# define FALSE 0

typedef struct s_control_obj
{
	int		player;
	int		exit;
	int		coin;
}	t_control_obj;

typedef struct s_map
{
	int		h;
	char	*max_line;
	char	**map;
	int		w;
}	t_map;

int		ft_checker_map(const char *file, t_map *map, t_control_obj *obj);
size_t	ft_strlen(char *s);
int		ft_contenet_map(t_map *map, t_control_obj *obj);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
size_t	find_newline(char *s);

#endif