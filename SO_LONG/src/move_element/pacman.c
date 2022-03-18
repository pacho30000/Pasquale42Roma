/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pacman.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 06:23:09 by pcatapan          #+#    #+#             */
/*   Updated: 2022/03/18 07:14:46 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	ft_fill_to_img_pacman(t_img *img, void *mlx_ptr)
{
	img->pacman_close = mlx_xpm_file_to_image(mlx_ptr, PAC_CLOSE, \
	&img->w, &img->h);
	img->pacman_dw = mlx_xpm_file_to_image(mlx_ptr, PAC_DW, \
	&img->w, &img->h);
	img->pacman_dx = mlx_xpm_file_to_image(mlx_ptr, PAC_DX, \
	&img->w, &img->h);
	img->pacman_sx = mlx_xpm_file_to_image(mlx_ptr, PAC_SX, \
	&img->w, &img->h);
	img->pacman_up = mlx_xpm_file_to_image(mlx_ptr, PAC_UP, \
	&img->w, &img->h);
	img->pacman_open_dw = mlx_xpm_file_to_image(mlx_ptr, PAC_O_DW, \
	&img->w, &img->h);
	img->pacman_open_dx = mlx_xpm_file_to_image(mlx_ptr, PAC_O_DX, \
	&img->w, &img->h);
	img->pacman_open_sx = mlx_xpm_file_to_image(mlx_ptr, PAC_O_SX, \
	&img->w, &img->h);
	img->pacman_open_up = mlx_xpm_file_to_image(mlx_ptr, PAC_O_UP, \
	&img->w, &img->h);
}
