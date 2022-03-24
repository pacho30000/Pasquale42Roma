/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_struct.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 04:08:45 by pcatapan          #+#    #+#             */
/*   Updated: 2022/03/24 07:11:33 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_STRUCT_H
# define  SO_LONG_STRUCT_H

# define WALL "/Users/pcatapan/Desktop/42/SO_LONG/asset/wall.xpm"
# define BACK_G "/Users/pcatapan/Desktop/42/SO_LONG/asset/beckg.xpm"
# define COLLECT "/Users/pcatapan/Desktop/42/SO_LONG/asset/collect.xpm"
# define EXIT "/Users/pcatapan/Desktop/42/SO_LONG/asset/exit.xpm"
# define BLU_DW_1 "/Users/pcatapan/Desktop/42/SO_LONG/asset/blu_dw_1.xpm"
# define BLU_DW_2 "/Users/pcatapan/Desktop/42/SO_LONG/asset/blu_dw_2.xpm"
# define BLU_UP_1 "/Users/pcatapan/Desktop/42/SO_LONG/asset/blu_up_1.xpm"
# define BLU_UP_2 "/Users/pcatapan/Desktop/42/SO_LONG/asset/blu_up_2.xpm"
# define BLU_SX_1 "/Users/pcatapan/Desktop/42/SO_LONG/asset/blu_sx_1.xpm"
# define BLU_SX_2 "/Users/pcatapan/Desktop/42/SO_LONG/asset/blu_sx_2.xpm"
# define BLU_DX_1 "/Users/pcatapan/Desktop/42/SO_LONG/asset/blu_dx_1.xpm"
# define BLU_DX_2 "/Users/pcatapan/Desktop/42/SO_LONG/asset/blu_dx_2.xpm"
# define ORANGE_DW_1 "/Users/pcatapan/Desktop/42/SO_LONG/asset/orange_dw_1.xpm"
# define ORANGE_DW_2 "/Users/pcatapan/Desktop/42/SO_LONG/asset/orange_dw_2.xpm"
# define ORANGE_UP_1 "/Users/pcatapan/Desktop/42/SO_LONG/asset/orange_up_1.xpm"
# define ORANGE_UP_2 "/Users/pcatapan/Desktop/42/SO_LONG/asset/orange_up_2.xpm"
# define ORANGE_SX_1 "/Users/pcatapan/Desktop/42/SO_LONG/asset/orange_sx_1.xpm"
# define ORANGE_SX_2 "/Users/pcatapan/Desktop/42/SO_LONG/asset/orange_sx_2.xpm"
# define ORANGE_DX_1 "/Users/pcatapan/Desktop/42/SO_LONG/asset/orange_dx_1.xpm"
# define ORANGE_DX_2 "/Users/pcatapan/Desktop/42/SO_LONG/asset/orange_dx_2.xpm"
# define RED_DW_1 "/Users/pcatapan/Desktop/42/SO_LONG/asset/red_dw_1.xpm"
# define RED_DW_2 "/Users/pcatapan/Desktop/42/SO_LONG/asset/red_dw_2.xpm"
# define RED_UP_1 "/Users/pcatapan/Desktop/42/SO_LONG/asset/red_up_1.xpm"
# define RED_UP_2 "/Users/pcatapan/Desktop/42/SO_LONG/asset/red_up_2.xpm"
# define RED_SX_1 "/Users/pcatapan/Desktop/42/SO_LONG/asset/red_sx_1.xpm"
# define RED_SX_2 "/Users/pcatapan/Desktop/42/SO_LONG/asset/red_sx_2.xpm"
# define RED_DX_1 "/Users/pcatapan/Desktop/42/SO_LONG/asset/red_dx_1.xpm"
# define RED_DX_2 "/Users/pcatapan/Desktop/42/SO_LONG/asset/red_dx_2.xpm"
# define PINK_DW_1 "/Users/pcatapan/Desktop/42/SO_LONG/asset/pink_dw_1.xpm"
# define PINK_DW_2 "/Users/pcatapan/Desktop/42/SO_LONG/asset/pink_dw_2.xpm"
# define PINK_UP_1 "/Users/pcatapan/Desktop/42/SO_LONG/asset/pink_up_1.xpm"
# define PINK_UP_2 "/Users/pcatapan/Desktop/42/SO_LONG/asset/pink_up_2.xpm"
# define PINK_SX_1 "/Users/pcatapan/Desktop/42/SO_LONG/asset/pink_sx_1.xpm"
# define PINK_SX_2 "/Users/pcatapan/Desktop/42/SO_LONG/asset/pink_sx_2.xpm"
# define PINK_DX_1 "/Users/pcatapan/Desktop/42/SO_LONG/asset/pink_dx_1.xpm"
# define PINK_DX_2 "/Users/pcatapan/Desktop/42/SO_LONG/asset/pink_dx_2.xpm"
# define PAC_CLOSE "/Users/pcatapan/Desktop/42/SO_LONG/asset/pacman_close.xpm"
# define PAC_DW "/Users/pcatapan/Desktop/42/SO_LONG/asset/pacman_dw.xpm"
# define PAC_DX "/Users/pcatapan/Desktop/42/SO_LONG/asset/pacman_dx.xpm"
# define PAC_SX "/Users/pcatapan/Desktop/42/SO_LONG/asset/pacman_sx.xpm"
# define PAC_UP "/Users/pcatapan/Desktop/42/SO_LONG/asset/pacman_up.xpm"
# define PAC_O_DW "/Users/pcatapan/Desktop/42/SO_LONG/asset/pacman_open_dw.xpm"
# define PAC_O_DX "/Users/pcatapan/Desktop/42/SO_LONG/asset/pacman_open_dx.xpm"
# define PAC_O_SX "/Users/pcatapan/Desktop/42/SO_LONG/asset/pacman_open_sx.xpm"
# define PAC_O_UP "/Users/pcatapan/Desktop/42/SO_LONG/asset/pacman_open_up.xpm"
# define ZERO "/Users/pcatapan/Desktop/42/SO_LONG/asset/point.xpm"

typedef struct s_img
{
	int		w;
	int		h;
	void	*back_g;
	void	*wall;
	void	*zero;
	void	*exit;
	void	*blu_dw;
	void	*blu_up;
	void	*blu_sx;
	void	*blu_dx;
	void	*oran_dw;
	void	*oran_up;
	void	*oran_sx;
	void	*oran_dx;
	void	*red_dw;
	void	*red_up;
	void	*red_sx;
	void	*red_dx;
	void	*pink_dw;
	void	*pink_up;
	void	*pink_sx;
	void	*pink_dx;
	void	*pacman_close;
	void	*pacman_dw;
	void	*pacman_dx;
	void	*pacman_sx;
	void	*pacman_up;
	void	*pacman_open_dw;
	void	*pacman_open_dx;
	void	*pacman_open_sx;
	void	*pacman_open_up;
	void	*collezionabile;
}	t_img;

#endif