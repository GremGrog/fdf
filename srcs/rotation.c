/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 14:42:57 by yquaro            #+#    #+#             */
/*   Updated: 2020/11/04 14:43:17 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	rotate_x(t_point *d, t_cam *camera)
{
	int previous_y;

	previous_y = d->y;
	d->y = previous_y * cos(ft_radian(camera->alpha))\
				+ d->z * sin(ft_radian(camera->alpha));
}

void	rotate_y(t_point *d, t_cam *camera)
{
	int previous_x;

	previous_x = d->x;
	d->x = previous_x * cos(ft_radian(camera->beta))\
							+ d->z * sin(ft_radian(camera->beta));
}

void	rotate_z(t_point *d, t_cam *camera)
{
	int previous_x;
	int previous_y;

	previous_x = d->x;
	previous_y = d->y;
	d->x = previous_x * cos(ft_radian(camera->gamma))\
								- previous_y * sin(ft_radian(camera->gamma));
	d->y = previous_x * sin(ft_radian(camera->gamma))\
								+ previous_y * cos(ft_radian(camera->gamma));
}

void	normalize_degree_value(t_cam *camera)
{
	if (fabs(camera->alpha) >= 360.0)
		camera->alpha = 0.0;
	if (fabs(camera->beta) >= 360.0)
		camera->beta = 0.0;
	if (fabs(camera->gamma) >= 360.0)
		camera->gamma = 0.0;
}

void	rotate_figure(int key, t_mlx *mlx)
{
	int i;

	i = 0;
	if (key != Q && key != W && key != A && key != S && key != Z && key != X)
		return ;
	while (i < mlx->img->grid_square)
	{
		if (key == Q)
			mlx->img->camera->alpha -= mlx->img->rotation_step;
		else if (key == W)
			mlx->img->camera->alpha += mlx->img->rotation_step;
		else if (key == A)
			mlx->img->camera->beta -= mlx->img->rotation_step;
		else if (key == S)
			mlx->img->camera->beta += mlx->img->rotation_step;
		else if (key == Z)
			mlx->img->camera->gamma -= mlx->img->rotation_step;
		else if (key == X)
			mlx->img->camera->gamma += mlx->img->rotation_step;
		normalize_degree_value(mlx->img->camera);
		check_image_front(mlx->img->camera);
		i++;
	}
}
