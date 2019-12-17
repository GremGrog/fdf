/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect_lines.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 16:22:21 by yquaro            #+#    #+#             */
/*   Updated: 2019/12/16 19:43:29 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void					image_clear(t_window *window)
{
	ft_bzero(window->mlx->data, window->mlx->img_width * window->mlx->img_height * (window->mlx->bbp / 8));
}

static void				bresenham_alg(t_window *window, t_pix d1, t_pix d2)
{
	int	deltaX = abs(d2.x - d1.x);
	int	deltaY = abs(d2.y - d1.y);
	int deltaError = (deltaX > deltaY ? deltaX : -deltaY) / 2;
	int error = deltaError;
	int x = d1.x;
	int	y = d1.y;
	while (1)
	{
		window->mlx->data[y * window->mlx->img_width + x] = 255 << 16 | 97 << 8 | 97;
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

void				connect_lines(t_window *window)
{
	int				i;
	int				j;

	i = 0;
	j = 0;
	image_clear(window);
	isometry(window);
	while (i < window->map.dots_num)
	{
		j = 0;
		while (j < window->map.dots_per_line)
		{
			if (j + 1 < window->map.dots_per_line)
				bresenham_alg(window, window->pxls[i], window->pxls[i + 1]);
			j++;
			i++;
		}
	}
	i = 0;
	while (i < window->map.dots_num)
	{
		if (i + window->map.dots_per_line < window->map.dots_num)
		bresenham_alg(window, window->pxls[i], window->pxls[i + window->map.dots_per_line]);
		i++;
	}
	mlx_put_image_to_window(window->mlx->mlx_ptr, \
		window->mlx->win_ptr, window->mlx->img_ptr, 0, 0);

}

