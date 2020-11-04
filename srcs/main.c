
#include "../fdf.h"

void	freee(t_mlx **mlx)
{
	ft_printf("freee\n");
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

void	terminate(t_mlx **mlx)
{
	ft_printf("terminate\n");
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

int		main(int argc, char **argv)
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
	if (mlx->img->grid_square > 1)
		connect_lines(mlx, mlx->img);
	else if (mlx->img->grid_square == 1)
		put_pixel(mlx);
	mlx_put_image_to_window(mlx->ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
	mlx_hook(mlx->win_ptr, 2, 0, key_press, mlx);
	mlx_hook(mlx->win_ptr, 17, 0, red_button, mlx);
	mlx_loop(mlx->ptr);
	freee(&mlx);
	return (1);
}
