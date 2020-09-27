/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   centering.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 17:54:13 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/09/30 17:57:51 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	centering(t_img *img)
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
	img->grid_width = img->grid_square / img->grid_height;
	margin_y = HEIGHT / 100 * 35;
	margin_x = WIDTH / 100 * 35;
	cube_height = (HEIGHT - margin_y * 2) / (img->grid_height - 1);
	cube_width = (WIDTH - margin_x * 2) / (img->grid_width - 1);
	start_x = margin_x;
	start_y = margin_y;
	i = 0;
	// ft_printf("%d %d\n", margin_x, margin_y);
	while (i < img->grid_square)
	{
		j = 0;
		while (j < img->grid_width)
		{
			img->dot[i].x = start_x;
			img->dot[i].y = start_y;
			start_x += cube_width;
			j++;
			i++;
		}
		start_x = margin_x;
		start_y += cube_height;
	}
}