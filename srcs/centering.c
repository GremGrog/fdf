/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   centering.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 17:54:13 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/09/30 17:57:51 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int margin_y = HEIGHT / 100 * 35;
int margin_x = WIDTH / 100 * 35;

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
			img->dot[i].x = start_x;
			img->dot[i].y = start_y;
			start_x += cube_width;
			j++;
			i++;
		}
		start_x = -1 * (cube_width * (img->grid_width - 1)) / 2;
		start_y -= cube_height;
	}
}

void	centering(t_img *img)
{
	int	cube_width;
	int	cube_height;


	if (img->grid_square % img->grid_height != 0)
	{
		ft_printf("Error\n");
		exit (-1);
	}
	
	img->grid_width = img->grid_square / img->grid_height; 
	cube_height = (HEIGHT - margin_y * 2) / (img->grid_height - 1);
	cube_width = (WIDTH - margin_x * 2) / (img->grid_width - 1);
	centering_loop(img, cube_width, cube_height);
}