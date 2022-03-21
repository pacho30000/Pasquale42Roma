/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orange.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 06:18:44 by pcatapan          #+#    #+#             */
/*   Updated: 2022/03/18 07:11:15 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	ft_fill_to_img_orange(t_img *img, void *mlx_ptr)
{
	img->orange_dw_1 = mlx_xpm_file_to_image(mlx_ptr, ORANGE_DW_1, \
		&img->w, &img->h);
	img->orange_dw_2 = mlx_xpm_file_to_image(mlx_ptr, ORANGE_DW_2, \
	&img->w, &img->h);
	img->orange_dx_1 = mlx_xpm_file_to_image(mlx_ptr, ORANGE_DX_1, \
	&img->w, &img->h);
	img->orange_dx_2 = mlx_xpm_file_to_image(mlx_ptr, ORANGE_DX_2, \
	&img->w, &img->h);
	img->orange_sx_1 = mlx_xpm_file_to_image(mlx_ptr, ORANGE_SX_1, \
	&img->w, &img->h);
	img->orange_sx_2 = mlx_xpm_file_to_image(mlx_ptr, ORANGE_SX_2, \
	&img->w, &img->h);
	img->orange_up_1 = mlx_xpm_file_to_image(mlx_ptr, ORANGE_UP_1, \
	&img->w, &img->h);
	img->orange_up_2 = mlx_xpm_file_to_image(mlx_ptr, ORANGE_UP_2, \
	&img->w, &img->h);
}
