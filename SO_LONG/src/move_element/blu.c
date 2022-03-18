/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blu.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 06:22:00 by pcatapan          #+#    #+#             */
/*   Updated: 2022/03/18 07:09:42 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	ft_fill_to_img_blu(t_img *img, void *mlx_ptr)
{
	img->blu_dw_1 = mlx_xpm_file_to_image(mlx_ptr, BLU_DW_1, &img->w, &img->h);
	img->blu_dw_2 = mlx_xpm_file_to_image(mlx_ptr, BLU_DW_2, &img->w, &img->h);
	img->blu_dx_1 = mlx_xpm_file_to_image(mlx_ptr, BLU_DX_1, &img->w, &img->h);
	img->blu_dx_2 = mlx_xpm_file_to_image(mlx_ptr, BLU_DX_2, &img->w, &img->h);
	img->blu_sx_1 = mlx_xpm_file_to_image(mlx_ptr, BLU_SX_1, &img->w, &img->h);
	img->blu_sx_2 = mlx_xpm_file_to_image(mlx_ptr, BLU_SX_2, &img->w, &img->h);
	img->blu_up_1 = mlx_xpm_file_to_image(mlx_ptr, BLU_UP_1, &img->w, &img->h);
	img->blu_up_2 = mlx_xpm_file_to_image(mlx_ptr, BLU_UP_2, &img->w, &img->h);
}
