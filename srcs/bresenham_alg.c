/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_alg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 13:29:16 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/10/01 16:16:10 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	bresenham_alg(t_mlx *mlx, t_coord d1_actual, t_coord d2_actual)
{
	int deltaX;
	int deltaY;
	int deltaError;
	int error;
	int x;
	int y;

	d1_actual.x = WIDTH / 2 + d1_actual.x;
	d1_actual.y = HEIGHT / 2 - d1_actual.y;

	d2_actual.x = WIDTH / 2 + d2_actual.x;
	d2_actual.y = HEIGHT / 2 - d2_actual.y;

	deltaX = abs(d2_actual.x - d1_actual.x);
	deltaY = abs(d2_actual.y - d1_actual.y);
	deltaError = (deltaX > deltaY ? deltaX : -deltaY) / 2;
	error = deltaError;
	x = d1_actual.x;
	y = d1_actual.y;
	while (1)
	{
		mlx->data[y * WIDTH + x] = 255 << 16 | 97 << 8 | 97;
		if (x == d2_actual.x && y == d2_actual.y)
			break ;
		error = deltaError;
		if (error > -deltaX)
		{
			deltaError -= deltaY;
			x += (d1_actual.x < d2_actual.x) ? 1 : -1;
		}
		if (error < deltaY)
		{
			deltaError += deltaX;
			y += (d1_actual.y < d2_actual.y) ? 1 : -1;
		}
	}
}

void	connect_lines(t_mlx *mlx, t_img *img)
{
	int	i;
	int	j;

	i = 0;
	while (i < img->grid_height)
	{
		j = 0;
		while (j < img->grid_width)
		{
			// horizontal
			if (j < img->grid_width - 1)
			{
				bresenham_alg(mlx, img->dot[i * img->grid_width + j], img->dot[(i * img->grid_width + j) + 1]);
			}
			// vertical
			if (i < img->grid_height - 1)
			{
				bresenham_alg(mlx, img->dot[i * img->grid_width + j], img->dot[(i + 1) * img->grid_width + j]);
			}
			j++;
		}
		i++;
	}
}
