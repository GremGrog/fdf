
#include "../fdf.h"

void	terminate(t_mlx *mlx)
{
	if (mlx->img->point != NULL)
		free(mlx->img->point);
	if (mlx->img->reset_point != NULL)
		free(mlx->img->reset_point);
	if (mlx->img->camera != NULL)
		free(mlx->img->camera);
	free(mlx->img);
	free(mlx->img_ptr);
	free(mlx->win_ptr);
	free(mlx->data);
	free(mlx->ptr);
	free(mlx);
}

int		main(int argc, char **argv)
{
	t_mlx	*mlx;

	if (argc > 1 && argv)
	{
		change_color_pair();
		mlx = init_mlx();
		if (mlx == NULL || (input_processing(argv[1], mlx->img)) != 0)
		{
			terminate(mlx);
			ft_printf("Error\n");
			exit(-1);
		}
		centering(mlx->img);
		save_defaults(mlx->img);
		isometry(mlx->img);
		accept_rotation_to_image(mlx);
		connect_lines(mlx, mlx->img);
		mlx_put_image_to_window(mlx->ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
		mlx_hook(mlx->win_ptr, 2, 0, key_press, mlx);
		mlx_hook(mlx->win_ptr, 17, 0, red_button, mlx);
		mlx_loop(mlx->ptr);
	}
}
