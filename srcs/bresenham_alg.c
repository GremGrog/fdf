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

void		bresenham_loop(t_point delta, t_mlx *mlx,\
					t_point d1_actual, t_point d2_actual)
{
	int		delta_error;
	int		error;
	t_point	cur;

	delta_error = (delta.x > delta.y ? delta.x : -delta.y) / 2;
	error = delta_error;
	cur.x = d1_actual.x;
	cur.y = d1_actual.y;
	while (!(cur.x == d2_actual.x && cur.y == d2_actual.y))
	{
		if ((cur.y <= HEIGHT && cur.y >= 0) && (cur.x <= WIDTH && cur.x >= 0))
			mlx->data[cur.y * WIDTH + cur.x] =\
					get_color(d1_actual, d2_actual, delta, cur);
		error = delta_error;
		if (error > -delta.x)
		{
			delta_error -= delta.y;
			cur.x += (d1_actual.x < d2_actual.x) ? 1 : -1;
		}
		if (error < delta.y)
		{
			delta_error += delta.x;
			cur.y += (d1_actual.y < d2_actual.y) ? 1 : -1;
		}
	}
}

void		bresenham_alg(t_mlx *mlx, t_point d1_actual, t_point d2_actual)
{
	t_point	delta;

	d1_actual.x = WIDTH / 2 + d1_actual.x + d1_actual.x_shift;
	d1_actual.y = HEIGHT / 2 - d1_actual.y - d1_actual.y_shift;
	d2_actual.x = WIDTH / 2 + d2_actual.x + d2_actual.x_shift;
	d2_actual.y = HEIGHT / 2 - d2_actual.y - d2_actual.y_shift;
	delta.x = abs(d2_actual.x - d1_actual.x);
	delta.y = abs(d2_actual.y - d1_actual.y);
	bresenham_loop(delta, mlx, d1_actual, d2_actual);
}

void		connect_lines(t_mlx *mlx, t_img *img)
{
	int	i;
	int	j;

	i = 0;
	while (i < img->grid_height)
	{
		j = 0;
		while (j < img->grid_width)
		{
			if (j < img->grid_width - 1)
				bresenham_alg(mlx, img->point[i * img->grid_width + j],\
									img->point[(i * img->grid_width + j) + 1]);
			if (i < img->grid_height - 1)
				bresenham_alg(mlx, img->point[i * img->grid_width + j],\
									img->point[(i + 1) * img->grid_width + j]);
			j++;
		}
		i++;
	}
}

void		put_pixel(t_mlx *mlx)
{
	int		x;
	int		y;
	
	x = WIDTH / 2 + mlx->img->point[0].x + mlx->img->point[0].x_shift;
	y = HEIGHT / 2 - mlx->img->point[0].y - mlx->img->point[0].y_shift;
	mlx->data[y * WIDTH + x] = 255 | 255 | 1;
}
