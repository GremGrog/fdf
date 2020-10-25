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
	t_coord delta;
	t_coord current;
	int deltaError;
	int error;

	d1_actual.x = WIDTH / 2 + d1_actual.x;
	d1_actual.y = HEIGHT / 2 - d1_actual.y;

	d2_actual.x = WIDTH / 2 + d2_actual.x;
	d2_actual.y = HEIGHT / 2 - d2_actual.y;

	delta.x = abs(d2_actual.x - d1_actual.x);
	delta.y = abs(d2_actual.y - d1_actual.y); 

	deltaError = (delta.x > delta.y ? delta.x : -delta.y) / 2;
	error = deltaError;
	current.x = d1_actual.x;
	current.y = d1_actual.y;
	while (1)
	{
		mlx->data[current.y * WIDTH + current.x] = get_color(d1_actual, d2_actual, delta, current);
		if (current.x == d2_actual.x && current.y == d2_actual.y)
			break ;
		error = deltaError;
		if (error > -delta.x)
		{
			deltaError -= delta.y;
			current.x += (d1_actual.x < d2_actual.x) ? 1 : -1;
		}
		if (error < delta.y)
		{
			deltaError += delta.x;
			current.y += (d1_actual.y < d2_actual.y) ? 1 : -1;
		}
	}
}

void	connect_lines(t_mlx *mlx, t_img *img)
{
	int	i;
	int	j;

	i = 0;
	while (i < img->grid_square)
	{
		rotate_x(&(mlx->img->dot[i]), mlx->camera);
		rotate_y(&(mlx->img->dot[i]), mlx->camera);
		rotate_z(&(mlx->img->dot[i]), mlx->camera);
		i++;
	}
	i = 0;
	while (i < img->grid_height)
	{
		j = 0;
		while (j < img->grid_width)
		{
			// horizontal
			if (j < img->grid_width - 1)
				bresenham_alg(mlx, img->dot[i * img->grid_width + j], img->dot[(i * img->grid_width + j) + 1]);
			// vertical
			if (i < img->grid_height - 1)
				bresenham_alg(mlx, img->dot[i * img->grid_width + j], img->dot[(i + 1) * img->grid_width + j]);
			j++;
		}
		i++;
	}
}
