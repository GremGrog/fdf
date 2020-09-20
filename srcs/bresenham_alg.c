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

void	bresenham_alg(t_mlx *mlx, t_coord d1, t_coord d2)
{
	int	deltaX = abs(d2.x - d1.x);
	int	deltaY = abs(d2.y - d1.y);
	int deltaError = (deltaX > deltaY ? deltaX : -deltaY) / 2;
	int error = deltaError;
	int x = d1.x;
	int	y = d1.y;
	while (1)
	{
		mlx->data[y * WIDTH + x] = 255 << 16 | 97 << 8 | 97;
		if (x == d2.x && y == d2.y)
			break ;
		error = deltaError;
		if (error > -deltaX)
		{
			deltaError -= deltaY;
			x += (d1.x < d2.x) ? 1 : -1;
		}
		if (error < deltaY)
		{
			deltaError += deltaX;
			y += (d1.y < d2.y) ? 1 : -1;
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
				bresenham_alg(mlx, img->dot[i*img->grid_width + j], img->dot[(i*img->grid_width + j) + 1]);
			// vertical
			if (i < img->grid_height - 1)
				bresenham_alg(mlx, img->dot[i*img->grid_width + j], img->dot[(i+1)*img->grid_width + j]);
			j++;
		}
		i++;
	}
}
