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

void	bresenham_alg(t_img *img, t_pix d1, t_pix d2)
{
	int	deltaX = abs(d2.x - d1.x);
	int	deltaY = abs(d2.y - d1.y);
	int deltaError = (deltaX > deltaY ? deltaX : -deltaY) / 2;
	int error = deltaError;
	int x = d1.x;
	int	y = d1.y;
	while (1)
	{
		img->data[y * img->img_width + x] = 255 << 16 | 97 << 8 | 97;
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

void	connect_lines(t_img *img)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < img->grid_square)
	{
		j = 0;
		while (j < img->grid_length)
		{
			if (j + 1 < img->grid_length)
				bresenham_alg(img, img->pxls[i], img->pxls[i + 1]);
			j++;
			i++;
		}
	}
	i = 0;
	while (i < img->grid_square)
	{
		if (i + img->grid_length < img->grid_square)
			bresenham_alg(img, img->pxls[i], img->pxls[i + img->grid_length]);
		i++;
	}
}
