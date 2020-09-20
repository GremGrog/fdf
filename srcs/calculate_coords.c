/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_coords.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 17:54:13 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/09/30 17:57:51 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	calculate_coords(t_img *img)
{
	int	margin_x;
	int	margin_y;
	int	start_x;
	int	start_y;
	int	cube_width;
	int	cube_height;
	int	i;
	int	j;

	// if (img->grid_square % img->grid_height != 0)
	// {
	// 	ft_printf("Error\n");
	// 	exit (-1);
	// }
	img->grid_length = img->grid_square / img->grid_height;
	margin_y = img->img_height / 100 * 35;
	margin_x = img->img_width / 100 * 35;
	cube_height = (img->img_height - margin_y * 2) / (img->grid_height - 1);
	cube_width = (img->img_width - margin_x * 2) / (img->grid_length - 1);
	start_x = margin_x;
	start_y = margin_y;
	i = 0;
	// ft_printf("%d %d\n", margin_x, margin_y);
	while (i < img->grid_square)
	{
		j = 0;
		while (j < img->grid_length)
		{
			img->pxls[i].x = start_x;
			img->pxls[i].y = start_y;
			start_x += cube_width;
			j++;
			i++;
		}
		start_x = margin_x;
		start_y += cube_height;
	}
}