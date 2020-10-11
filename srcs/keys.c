#include "../fdf.h"

int		key_press(int key, void *param)
{
	t_mlx	*mlx;
	int		i;

	mlx = (t_mlx *)param;
	ft_bzero(mlx->data, HEIGHT * WIDTH * (mlx->bbp / 8));
	centering(mlx->img);
	if (key == 126) {
		i = 0;
		while (i < mlx->img->grid_square)
		{
			if (mlx->img->dot[i].bump == TRUE)
				mlx->img->dot[i].z++;
			i++;
		}
	}
	else if (key == 125)
	{
		i = 0;
		while (i < mlx->img->grid_square)
		{
			if (mlx->img->dot[i].bump == TRUE)
				mlx->img->dot[i].z--;
			i++;
		}
	}
	else if (key == 123 || key == 124)
	{
		rotate_figure(key, mlx);
	}
	else if (key == 12 || key == 53)
	{ // press Q to quit
		// terminate()
		exit(1);
	}
	isometry(mlx->img, mlx->camera);
	connect_lines(mlx, mlx->img);
	mlx_put_image_to_window(mlx->ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
	return 0;
}

int red_button(void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	// terminate()
	exit(1);
}