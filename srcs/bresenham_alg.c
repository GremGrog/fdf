/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_alg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 13:29:16 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/09/24 13:30:23 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	bresenham_alg(t_img *img)
{
	int p1 = 200 * img->img_width + 300;
	int x1 = p1 % img->img_width;
	int y1 = p1 / img->img_height;
	int p2 = 150 * img->img_width + 0;
	int x2 = p2 % img->img_width;
	int y2 = p2 / img->img_height;
	// img->data[p1] = 255 << 16 | 255 << 8 | 255;
	// img->data[p2] = 255 << 16 | 255 << 8 | 255;

	int	deltaX = abs(x2 - x1);
	int	deltaY = abs(y2 - y1);
	int deltaError = (deltaX > deltaY ? deltaX : -deltaY) / 2;
	int error = deltaError;
	int x = x1;
	int	y = y1;
	while (1)
	{
		img->data[y * img->img_width + x] = 255 << 16 | 255 << 8 | 255;
		if (x == x2 && y == y2)
			break ;
		error = deltaError;
		if (error > -deltaX)
		{
			deltaError -= deltaY;
			x += (x1 < x2) ? 1 : -1;
		}
		if (error < deltaY)
		{
			deltaError += deltaX;
			y += (y1 < y2) ? 1 : -1;
		}
	}
}