/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 14:40:17 by yquaro            #+#    #+#             */
/*   Updated: 2020/11/04 14:40:21 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	move_x_asix(t_img *img, int direction)
{
	int i;

	i = 0;
	if (direction == LEFT_DIRECTION && find_rightmost_point(img) <= -WIDTH / 2)
		return ;
	if (direction == RIGHT_DIRECTION && find_leftmost_point(img) >= WIDTH / 2)
		return ;
	while (i < img->grid_square)
	{
		if (direction == LEFT_DIRECTION)
			img->point[i].x_shift -= 10;
		else if (direction == RIGHT_DIRECTION)
			img->point[i].x_shift += 10;
		i++;
	}
}

void	move_y_asix(t_img *img, int direction)
{
	int i;

	i = 0;
	if (direction == UP_DIRECTION && find_lowest_point(img) >= HEIGHT / 2)
		return ;
	if (direction == DOWN_DIRECTION && find_upmost_point(img) <= -HEIGHT / 2)
		return ;
	while (i < img->grid_square)
	{
		if (direction == UP_DIRECTION)
			img->point[i].y_shift += 10;
		else if (direction == DOWN_DIRECTION)
			img->point[i].y_shift -= 10;
		i++;
	}
}

void	move_image(int key, t_mlx *mlx)
{
	if (key == LEFT)
		move_x_asix(mlx->img, LEFT_DIRECTION);
	else if (key == RIGHT)
		move_x_asix(mlx->img, RIGHT_DIRECTION);
	else if (key == UP)
		move_y_asix(mlx->img, UP_DIRECTION);
	else if (key == DOWN)
		move_y_asix(mlx->img, DOWN_DIRECTION);
}
