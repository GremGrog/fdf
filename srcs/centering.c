/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   centering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 14:23:41 by yquaro            #+#    #+#             */
/*   Updated: 2020/11/04 14:23:52 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	centering_loop(t_img *img, int cube_width, int cube_height)
{
	int	i;
	int	j;
	int	start_x;
	int	start_y;

	i = 0;
	j = 0;
	start_x = -1 * (cube_width * (img->grid_width - 1)) / 2;
	start_y = (cube_height * (img->grid_height - 1)) / 2;
	i = 0;
	while (i < img->grid_square)
	{
		j = 0;
		while (j < img->grid_width)
		{
			img->point[i].x = start_x;
			img->point[i].y = start_y;
			start_x += cube_width;
			j++;
			i++;
		}
		start_x = -1 * (cube_width * (img->grid_width - 1)) / 2;
		start_y -= cube_height;
	}
}

void	centering(t_mlx *mlx)
{
	mlx->img->grid_width = mlx->img->grid_square / mlx->img->grid_height;
	if (mlx->img->grid_height == 1)
		mlx->img->cube_height = (HEIGHT - mlx->img->margin_y * 2);
	else
		mlx->img->cube_height = (HEIGHT - mlx->img->margin_y * 2) \
			/ (mlx->img->grid_height - 1);
	if (mlx->img->grid_width == 1)
		mlx->img->cube_width = (WIDTH - mlx->img->margin_x * 2);
	else
		mlx->img->cube_width = \
			(WIDTH - mlx->img->margin_x * 2) / (mlx->img->grid_width - 1);
	centering_loop(mlx->img, mlx->img->cube_width, mlx->img->cube_height);
}
