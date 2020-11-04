/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 14:21:17 by yquaro            #+#    #+#             */
/*   Updated: 2020/11/04 14:45:50 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void		set_rotation_step(t_img *img)
{
	if (img->grid_square > 1000)
		img->rotation_step /= 10.0;
	if (img->grid_square > 10000)
		img->rotation_step /= 10.0;
}

void		freee(t_mlx **mlx)
{
	if (*mlx == NULL)
		return ;
	if ((*mlx)->img->point != NULL)
		free((*mlx)->img->point);
	if ((*mlx)->img->reset_point != NULL)
		free((*mlx)->img->reset_point);
	if ((*mlx)->img->camera != NULL)
		free((*mlx)->img->camera);
	if ((*mlx)->img->color != NULL)
		free((*mlx)->img->color);
	if ((*mlx)->img != NULL)
		free((*mlx)->img);
	free((*mlx)->img_ptr);
	free((*mlx)->win_ptr);
	free((*mlx)->data);
	free((*mlx)->ptr);
	free((*mlx));
	(*mlx) = NULL;
}

void		terminate(t_mlx **mlx)
{
	freee(mlx);
	*mlx = NULL;
	ft_printf("Error\n");
	exit(-1);
}

static void	usage(void)
{
	ft_printf("usage: \'./fdf <map.fdf>\'\n");
	exit(1);
}

int			main(int argc, char **argv)
{
	t_mlx	*mlx;

	if (argc == 1)
		usage();
	mlx = init_mlx();
	if (mlx == NULL || (input_processing(argv[1], mlx)) != 0)
		terminate(&mlx);
	setting_parameters(mlx);
	centering(mlx);
	save_reset_point(mlx);
	isometry(mlx->img);
	accept_rotation_to_image(mlx);
	connect_lines(mlx, mlx->img);
	mlx_put_image_to_window(mlx->ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
	mlx_hook(mlx->win_ptr, 2, 0, key_press, mlx);
	mlx_hook(mlx->win_ptr, 17, 0, red_button, mlx);
	mlx_loop(mlx->ptr);
	freee(&mlx);
	return (1);
}
