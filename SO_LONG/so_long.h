/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 19:54:09 by pcatapan          #+#    #+#             */
/*   Updated: 2022/03/20 17:46:07 by pcatapan         ###   ########.fr       */
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
# define GREEN "\x1b[32m"
# define SIZE	48
# define UP 1
# define DW -1
# define DX 2
# define SX -2

typedef struct s_animate
{
	int					direction;
	void				*img;
	struct s_animate	*next;
	struct s_animate	*prev;
}	t_animate;

typedef struct s_sprite
{
	int			x;
	int			y;
	t_animate	*img;
}	t_sprite;

typedef struct s_control_obj
{
	int	player;
	int	exit;
	int	coin;
	int	enemy;
}	t_control_obj;

typedef struct s_map
{
	int				h;
	int				w;
	int				moves;
	char			*max_line;
	char			**map;
	void			*mlx_ptr;
	void			*window;
	t_sprite		*pacman;
	t_sprite		*red;
	t_sprite		*pink;
	t_sprite		*orange;
	t_sprite		*blu;
	t_img			*img;
	t_control_obj	*object;
}	t_map;

size_t	ft_strlen(char *s);
size_t	find_newline(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);
int		ft_check_maps_walls(t_map *map);
int		ft_checker_map(const char *file, t_map *map, t_control_obj *obj);
int		ft_content_map(t_map *map, t_control_obj *obj);
int		ft_count_element(t_map *map, t_control_obj *obj);
int		ft_move_pacman(int key, t_map *map);
int		ft_can_move(char c);
void	ft_creating_map(t_map *map);
void	ft_img(t_map *map);
void	ft_fill_to_img_red(t_img *img, void *mlx_ptr);
void	ft_animate_fix_red(t_map *map, int i);
void	ft_fill_to_img_orange(t_img *img, void *mlx_ptr);
void	ft_animate_fix_orange(t_map *map, int dir);
void	ft_fill_to_img_pink(t_img *img, void *mlx_ptr);
void	ft_animate_fix_pink(t_map *map, int dir);
void	ft_fill_to_img_blu(t_img *img, void *mlx_ptr);
void	ft_animate_fix_blu(t_map *map, int dir);
void	ft_fill_to_img_pacman(t_img *img, void *mlx_ptr);
void	ft_chang_img_direction(t_map *map, int y, int x, void *img);
void	ft_move(t_map *map);
void	ft_pacman_up(t_map *map);
void	ft_pacman_dw(t_map *game);
void	ft_pacman_dx(t_map *game);
void	ft_pacman_sx(t_map *game);

#endif