/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 10:29:51 by yquaro            #+#    #+#             */
/*   Updated: 2019/12/16 19:07:58 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void				calc_iso(t_window *window, t_pix *d)
{
	int previous_x;
    int previous_y;
	if (!window)
		return ;
    previous_x = d->x;
    previous_y = d->y;
    d->x = previous_x + (previous_x - previous_y) * cos(0.523599);
    d->y = -d->z + (previous_x + previous_y) * sin(0.523599);
}

void				isometry(t_window *window)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i != window->map.dots_num)
	{
		j = 0;
		while (j != window->map.dots_per_line)
		{
			calc_iso(window, &window->pxls[i]);
			j++;
			i++;
		}
	}
}

int 				main(int argc, char **argv)
{
	t_window		*window;

	if (argc == 1)
		return (0);
	window = mlx_initialization(argv);
	setup_controls(window);
	calculate_coords(window);
	connect_lines(window);
	mlx_loop(window->mlx->mlx_ptr);
	mlx_delete(&window);
}