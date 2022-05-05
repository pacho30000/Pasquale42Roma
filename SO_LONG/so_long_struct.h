/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_struct.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 04:08:45 by pcatapan          #+#    #+#             */
/*   Updated: 2022/05/05 17:58:09 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_STRUCT_H
# define  SO_LONG_STRUCT_H

# define WALL "asset/wall.xpm"
# define WALL2 "asset/wall2.xpm"
# define BACK_G "asset/bg.xpm"
# define COLLECT "asset/coin.xpm"
# define PLAYERSR "asset/playerR.xpm"
# define PLAYERSL "asset/playerL.xpm"
# define ENEMY1 "asset/enemy1.xpm"
# define ENEMY2 "asset/enemy2.xpm"
# define EXIT1 "asset/exit1.xpm"
# define EXIT2 "asset/exit2.xpm"

typedef struct s_img
{
	int		w;
	int		h;
	void	*back_g;
	void	*wall;
	void	*wall2;
	void	*player_r;
	void	*player_l;
	void	*enemy1;
	void	*enemy2;
	void	*collezionabile;
	void	*exit2;
	void	*exit1;
}	t_img;

#endif