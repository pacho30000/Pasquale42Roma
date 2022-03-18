/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 19:54:09 by pcatapan          #+#    #+#             */
/*   Updated: 2022/03/18 07:16:50 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./mlx/mlx.h"
# include "./PRINTF/ft_printf.h"
# include "so_long_struct.h"
# include <unistd.h>
# include <fcntl.h>

# define RED "\x1b[31m"
# define SIZE	48

typedef struct s_control_obj
{
	int		player;
	int		exit;
	int		coin;
	void	*wall;
}	t_control_obj;

typedef struct s_map
{
	int				h;
	char			*max_line;
	char			**map;
	int				w;
	void			*mlx_ptr;
	void			*window;
	t_img			*img;
	t_control_obj	object;
}	t_map;

int		ft_check_maps_walls(t_map *map);
int		ft_checker_map(const char *file, t_map *map, t_control_obj *obj);
int		ft_content_map(t_map *map, t_control_obj *obj);
int		ft_count_element(t_map *map, t_control_obj *obj);
size_t	ft_strlen(char *s);
size_t	find_newline(char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
void	ft_creating_map(t_map *map);
void	ft_img(t_map *map);
void	ft_fill_to_img_red(t_img *img, void *mlx_ptr);
void	ft_fill_to_img_orange(t_img *img, void *mlx_ptr);
void	ft_fill_to_img_pink(t_img *img, void *mlx_ptr);
void	ft_fill_to_img_blu(t_img *img, void *mlx_ptr);
void	ft_fill_to_img_pacman(t_img *img, void *mlx_ptr);
void	ft_fill_to_img_walls(t_img *img, void *mlx_ptr);

#endif