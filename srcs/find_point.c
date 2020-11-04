/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_point.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 14:37:37 by yquaro            #+#    #+#             */
/*   Updated: 2020/11/04 14:37:38 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int		find_rightmost_point(t_img *img)
{
	t_point	rightmost;
	int		i;

	i = 0;
	rightmost = img->point[i];
	while (i < img->grid_square)
	{
		if (rightmost.x + rightmost.x_shift <\
							img->point[i].x + img->point[i].x_shift)
			rightmost.x = img->point[i].x;
		i++;
	}
	return (rightmost.x + rightmost.x_shift);
}

int		find_leftmost_point(t_img *img)
{
	t_point	leftmost;
	int		i;

	i = 0;
	leftmost = img->point[i];
	while (i < img->grid_square)
	{
		if (leftmost.x + leftmost.x_shift >\
						img->point[i].x + img->point[i].x_shift)
			leftmost.x = img->point[i].x;
		i++;
	}
	return (leftmost.x + leftmost.x_shift);
}

int		find_lowest_point(t_img *img)
{
	t_point	lowest;
	int		i;

	i = 0;
	lowest = img->point[i];
	while (i < img->grid_square)
	{
		if (lowest.y > img->point[i].y)
			lowest.y = img->point[i].y;
		i++;
	}
	return (lowest.y + lowest.y_shift);
}

int		find_upmost_point(t_img *img)
{
	t_point	upmost;
	int		i;

	i = 0;
	upmost = img->point[i];
	while (i < img->grid_square)
	{
		if (upmost.y < img->point[i].y)
			upmost.y = img->point[i].y;
		i++;
	}
	return (upmost.y + upmost.y_shift);
}
