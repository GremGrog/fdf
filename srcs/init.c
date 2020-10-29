/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_new_img.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 14:03:42 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/09/30 15:38:51 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	set_rotation_step(t_img *img)
{
	if (img->grid_square > 1000)
		img->rotation_step /= 10.0;
	if (img->grid_square > 10000)
		img->rotation_step /= 10.0;
}

t_cam	*init_camera()
{
	t_cam	*cam;

	if (!(cam = (t_cam*)malloc(sizeof(t_cam))))
		return NULL;
	cam->alpha = 0.0;
	cam->beta = 0.0;
	cam->gamma = 0.0;
	cam->front = TRUE;
	cam->projection = ISO;
	return cam;
}

t_img	*init_img()
{
	t_img	*img;

	if (!(img = (t_img*)malloc(sizeof(t_img))))
		return NULL;
	img->grid_height = 0;
	img->grid_square = 0;
	img->grid_width = 0;
	img->cube_height = 0;
	img->cube_width = 0;
	img->margin_x = MARGIN_X;
	img->margin_y = MARGIN_Y;
	img->rotation_step = BASIC_ROTATION_STEP;
	img->dot = NULL;
	return (img);
}

t_mlx	*init_mlx()
{
	t_mlx	*mlx;

	if (!(mlx = (t_mlx*)malloc(sizeof(t_mlx))))
		return NULL;
	if ((mlx->img = init_img()) == NULL)
		return NULL;
	if ((mlx->camera = init_camera()) == NULL)
		return NULL;
	mlx->ptr = NULL;
	mlx->win_ptr = NULL;
	mlx->img_ptr = NULL;
	mlx->data = 0;
	mlx->bbp = 0;
	mlx->size_line = 0;
	mlx->endian = 0;
	mlx->ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->ptr, WIDTH, HEIGHT, WINDOW_NAME);
	mlx->img_ptr = mlx_new_image (mlx->ptr, WIDTH, HEIGHT);
	mlx->data = (int*)mlx_get_data_addr(mlx->img_ptr, &mlx->bbp, &mlx->size_line, &mlx->endian);
	return (mlx);
}
