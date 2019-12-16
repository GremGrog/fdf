/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_initialization.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 12:22:37 by yquaro            #+#    #+#             */
/*   Updated: 2019/12/16 15:03:13 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_window			*window_init(void)
{
	t_window			*window;

	if ((window = (t_window *)malloc(sizeof(t_window))) == NULL)
		exit(-1);
	if ((window->mlx = (t_mlx *)malloc(sizeof(t_mlx))) == NULL)
	{
		free(window);
		exit(-1);
	}
	return (window);
}

static void				set_initial_store(t_window **window)
{
	(*window)->mlx->mlx_ptr = NULL;
	(*window)->map.num_of_lines = 0;
	(*window)->map.dots_num = 0;
	(*window)->map.dots_per_line = 0;
	(*window)->mlx->win_ptr = NULL;
	(*window)->mlx->img_ptr = NULL;
	(*window)->mlx->win_width = 1500;
	(*window)->mlx->win_height = 1500;
	(*window)->mlx->img_width = 1500;
	(*window)->mlx->img_height = 1500;
	(*window)->mlx->data = 0;
	(*window)->mlx->bbp = 32;
	(*window)->mlx->size_line = 3200;
	(*window)->mlx->endian = 1;
}

t_window			*mlx_initialization(char **argv)
{
	t_window		*window;

	window = window_init();
	set_initial_store(&window);
	input_processing(argv[1], window);
	window->mlx->mlx_ptr = mlx_init();
	window->mlx->win_ptr = mlx_new_window(window->mlx->mlx_ptr, \
		window->mlx->win_width, window->mlx->win_height, "fdf");
	window->mlx->img_ptr = mlx_new_image(window->mlx->mlx_ptr, \
		window->mlx->img_width, window->mlx->img_height);
	window->mlx->data = (int *)mlx_get_data_addr(window->mlx->img_ptr, \
		&window->mlx->bbp, &window->mlx->size_line, &window->mlx->endian);
	return (window);
}

static void			zeroing(t_window **window)
{
	(*window)->mlx->mlx_ptr = NULL;
	(*window)->map.num_of_lines = 0;
	(*window)->map.dots_num = 0;
	(*window)->map.dots_per_line = 0;
	(*window)->mlx->win_ptr = NULL;
	(*window)->mlx->img_ptr = NULL;
	(*window)->mlx->win_width = 0;
	(*window)->mlx->win_height = 0;
	(*window)->mlx->img_width = 0;
	(*window)->mlx->img_height = 0;
	(*window)->mlx->data = 0;
	(*window)->mlx->bbp = 0;
	(*window)->mlx->size_line = 0;
	(*window)->mlx->endian = 0;
}

void				mlx_delete(t_window **window)
{
	zeroing(window);
	free((*window)->mlx);
	(*window)->mlx = NULL;
	free((*window)->pxls);
	(*window)->pxls = NULL;
	free(*window);
	*window = NULL;
}
