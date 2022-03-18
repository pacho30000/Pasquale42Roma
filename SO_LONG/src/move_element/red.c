/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 03:20:38 by pcatapan          #+#    #+#             */
/*   Updated: 2022/03/18 07:13:39 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	ft_fill_to_img_red(t_img *img, void *mlx_ptr)
{
	img->red_dw_1 = mlx_xpm_file_to_image(mlx_ptr, RED_DW_1, &img->w, &img->h);
	img->red_dw_2 = mlx_xpm_file_to_image(mlx_ptr, RED_DW_2, &img->w, &img->h);
	img->red_dx_1 = mlx_xpm_file_to_image(mlx_ptr, RED_DX_1, &img->w, &img->h);
	img->red_dx_2 = mlx_xpm_file_to_image(mlx_ptr, RED_DX_2, &img->w, &img->h);
	img->red_sx_1 = mlx_xpm_file_to_image(mlx_ptr, RED_SX_1, &img->w, &img->h);
	img->red_sx_2 = mlx_xpm_file_to_image(mlx_ptr, RED_SX_2, &img->w, &img->h);
	img->red_up_1 = mlx_xpm_file_to_image(mlx_ptr, RED_UP_1, &img->w, &img->h);
	img->red_up_2 = mlx_xpm_file_to_image(mlx_ptr, RED_UP_2, &img->w, &img->h);
}
