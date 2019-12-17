/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_coords.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 16:19:02 by yquaro            #+#    #+#             */
/*   Updated: 2019/12/16 20:03:33 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	calculate_coords(t_window *window)
{
	int	margin_x;
	int	margin_y;
	int	start_x;
	int	start_y;
	int	cube_width;
	int	cube_height;
	int	i;
	int	j;

	// if (img->dots_num % img->num_of_lines != 0)
	// {
	// 	ft_printf("Error\n");
	// 	exit (-1);
	// }
	window->map.dots_per_line = window->map.dots_num / window->map.num_of_lines;
	margin_y = window->mlx->img_height / 100 * 35;
	margin_x = window->mlx->img_width / 100 * 35;
	cube_height = (window->mlx->img_height - margin_y * 2) / (window->map.num_of_lines - 1);
	cube_width = (window->mlx->img_width - margin_x * 2) / (window->map.dots_per_line - 1);
	start_x = 0 + margin_x;
	start_y = 0 + margin_y;
	i = 0;
	// ft_printf("%d %d\n", margin_x, margin_y);
	while (i < window->map.dots_num)
	{
		j = 0;
		while (j < window->map.dots_per_line)	
		{
			window->pxls[i].x = start_x;
			window->pxls[i].y = start_y;
			start_x += cube_width;
			j++;
			i++;
		}
		start_x = 0 + margin_x;
		start_y += cube_height;
	}
}
