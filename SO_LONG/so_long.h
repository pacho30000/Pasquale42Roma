/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 19:54:09 by pcatapan          #+#    #+#             */
/*   Updated: 2022/05/05 18:17:13 by pcatapan         ###   ########.fr       */
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

typedef struct s_sprite
{
	int	x;
	int	y;
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
	int				animate;
	int				t_img;
	char			*max_line;
	char			**map;
	void			*mlx_ptr;
	void			*window;
	t_sprite		*player;
	t_img			*img;
	t_control_obj	*object;
}	t_map;

size_t		ft_strlen(char *s);
size_t		find_newline(char *s);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strchr(const char *s, int c);
int			ft_check_maps_walls(t_map *map);
int			ft_checker_map(const char *file, t_map *map, t_control_obj *obj);
int			ft_content_map(t_map *map, t_control_obj *obj);
int			ft_count_element(t_control_obj *obj);
int			ft_move_player(int key, t_map *map);
int			ft_can_move(char c);
int			ft_see_enemy(t_map *map, int x, int y);
int			ft_can_enemy(t_map *map, int x, int y);
void		ft_creating_map(t_map *map);
void		ft_img(t_map *map);
void		ft_fill_to_img_player(t_img *img, void *mlx_ptr);
int			ft_can_player(char c, t_map *map);
void		ft_player_up(t_map *map);
void		ft_player_dw(t_map *game);
void		ft_player_dx(t_map *game);
void		ft_player_sx(t_map *game);
void		ft_move(t_map *map);
void		ft_print_map_in_shell(t_map *map, char **print);
void		ft_new_i(t_map *map, int x, int y, void *img);
void		ft_put_back_enemy(t_map *map, int x, int y);
int			ft_game_over(t_map *map);
void		ft_move_enemy(t_map *map, int x, int y);
char		*ft_itoa(int n);

//Animate.c
void		ft_animate_enemy(t_map *map, int x, int y);
void		ft_search_exit(t_map *map);

#endif