/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 14:03:42 by fmasha-h          #+#    #+#             */
/*   Updated: 2020/11/04 14:44:53 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_color			*init_color(void)
{
	t_color		*color;

	if ((color = (t_color *)malloc(sizeof(t_color))) == NULL)
		return (NULL);
	color->relief_color_borders = (int *)malloc(sizeof(int) * \
		MAX_NUMBER_OF_COLORS);
	if (color->relief_color_borders == NULL)
	{
		free(color);
		return (NULL);
	}
	ft_bzero(color->relief_color_borders, MAX_NUMBER_OF_COLORS);
	color->base_color_index = 0;
	color->size = 0;
	return (color);
}

t_cam			*init_camera(void)
{
	t_cam		*cam;

	if (!(cam = (t_cam *)malloc(sizeof(t_cam))))
		return (NULL);
	cam->alpha = 0.0;
	cam->beta = 0.0;
	cam->gamma = 0.0;
	cam->front = TRUE;
	cam->projection = ISO;
	return (cam);
}

t_img			*init_img(void)
{
	t_img		*img;

	if (!(img = (t_img *)malloc(sizeof(t_img))))
		return (NULL);
	if ((img->camera = init_camera()) == NULL)
	{
		free(img);
		return (NULL);
	}
	img->point = NULL;
	img->reset_point = NULL;
	img->grid_height = 0;
	img->grid_square = 0;
	img->grid_width = 0;
	img->cube_height = 0;
	img->cube_width = 0;
	img->margin_x = MARGIN_X;
	img->margin_y = MARGIN_Y;
	img->rotation_step = BASIC_ROTATION_STEP;
	return (img);
}

t_mlx			*init_mlx(void)
{
	t_mlx		*mlx;

	if (!(mlx = (t_mlx *)malloc(sizeof(t_mlx))))
		return (NULL);
	if ((mlx->img = init_img()) == NULL)
	{
		free(mlx);
		return (NULL);
	}
	mlx->ptr = NULL;
	mlx->win_ptr = NULL;
	mlx->img_ptr = NULL;
	mlx->data = 0;
	mlx->bbp = 0;
	mlx->size_line = 0;
	mlx->endian = 0;
	mlx->ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->ptr, WIDTH, HEIGHT, WINDOW_NAME);
	mlx->img_ptr = mlx_new_image(mlx->ptr, WIDTH, HEIGHT);
	mlx->data = (int*)mlx_get_data_addr(mlx->img_ptr, &mlx->bbp,\
		&mlx->size_line, &mlx->endian);
	return (mlx);
}
