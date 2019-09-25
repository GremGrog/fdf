/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_coords.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 17:54:13 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/09/25 20:28:17 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	calculate_coords(t_img *img)
{
	int	margin_x;
	int	margin_y;
	int	line_x;
	int	line_y;
	float	step_x;
	float	step_y;
	float	start_x;
	float	start_y;
	int	i;
	int	j;

	if (img->dots_num % img->num_of_lines != 0)
	{
		ft_printf("Error\n");
		exit (-1);
	}
	img->dots_per_line = img->dots_num / img->num_of_lines;
	margin_x = (img->img_width - (img->img_width / img->dots_per_line) * (img->dots_per_line - 1)) / 2;
	margin_y = (img->img_height - (img->img_height / img->num_of_lines) * (img->num_of_lines - 1)) / 2;
	line_x = img->img_width - (margin_x * 2);
	line_y = img->img_height - (margin_y * 2);
	step_x = line_x / img->dots_per_line;
	step_y = line_y / img->num_of_lines;
	start_x = 0 + margin_x;
	start_y = 0 + margin_y;
	i = 0;
	while (i < img->dots_num)
	{
		j = 0;
		while (j < img->dots_per_line)
		{
			img->pxls[i].x = start_x;
			img->pxls[i].y = start_y;
			ft_printf("%d %d\n", img->pxls[i].x, img->pxls[i].y);
			start_x += step_x;
			j++;
			i++;
		}
		start_x = 0 + margin_x;
		start_y += step_y;
	}
}