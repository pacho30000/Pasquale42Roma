/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pink.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 06:20:00 by pcatapan          #+#    #+#             */
/*   Updated: 2022/03/18 07:12:30 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	ft_fill_to_img_pink(t_img *img, void *mlx_ptr)
{
	img->pink_dw_1 = mlx_xpm_file_to_image(mlx_ptr, PINK_DW_1, \
		&img->w, &img->h);
	img->pink_dw_2 = mlx_xpm_file_to_image(mlx_ptr, PINK_DW_2, \
	&img->w, &img->h);
	img->pink_dx_1 = mlx_xpm_file_to_image(mlx_ptr, PINK_DX_1, \
	&img->w, &img->h);
	img->pink_dx_2 = mlx_xpm_file_to_image(mlx_ptr, PINK_DX_2, \
	&img->w, &img->h);
	img->pink_sx_1 = mlx_xpm_file_to_image(mlx_ptr, PINK_SX_1, \
	&img->w, &img->h);
	img->pink_sx_2 = mlx_xpm_file_to_image(mlx_ptr, PINK_SX_2, \
	&img->w, &img->h);
	img->pink_up_1 = mlx_xpm_file_to_image(mlx_ptr, PINK_UP_1, \
	&img->w, &img->h);
	img->pink_up_2 = mlx_xpm_file_to_image(mlx_ptr, PINK_UP_2, \
	&img->w, &img->h);
}
