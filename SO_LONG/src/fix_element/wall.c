/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 06:36:38 by pcatapan          #+#    #+#             */
/*   Updated: 2022/03/18 07:19:57 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	ft_fill_to_img_walls(t_img *img, void *mlx_ptr)
{
	img->wall_corner_c_dx_dw = mlx_xpm_file_to_image(mlx_ptr, W_C_C_DX_DW, \
	&img->w, &img->h);
	img->wall_corner_c_dx_up = mlx_xpm_file_to_image(mlx_ptr, W_C_C_DX_UP, \
	&img->w, &img->h);
	img->wall_corner_c_sx_dw = mlx_xpm_file_to_image(mlx_ptr, W_C_C_SX_DW, \
	&img->w, &img->h);
	img->wall_corner_c_sx_up = mlx_xpm_file_to_image(mlx_ptr, W_C_C_SX_UP, \
	&img->w, &img->h);
	img->wall_corner_dw = mlx_xpm_file_to_image(mlx_ptr, W_CR_DW, \
	&img->w, &img->h);
	img->wall_corner_dx = mlx_xpm_file_to_image(mlx_ptr, W_CR_DX, \
	&img->w, &img->h);
	img->wall_corner_sx = mlx_xpm_file_to_image(mlx_ptr, W_CR_SX, \
	&img->w, &img->h);
	img->wall_corner_up = mlx_xpm_file_to_image(mlx_ptr, W_CR_UP, \
	&img->w, &img->h);
	img->wall_horizontal = mlx_xpm_file_to_image(mlx_ptr, W_HORIZONTAL, \
	&img->w, &img->h);
	img->wall_vertical = mlx_xpm_file_to_image(mlx_ptr, W_VERTICAL, \
	&img->w, &img->h);
}
