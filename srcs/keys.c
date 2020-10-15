#include "../fdf.h"

void	handle_heigth_change(int key, t_mlx *mlx)
{
	int i;

	i = 0;
	while (i < mlx->img->grid_square)
	{
		if (mlx->img->dot[i].bump == TRUE)
		{
			if (key == UP_ARROW) 
				mlx->img->dot[i].z++;
			else if (key == DOWN_ARROW)
				mlx->img->dot[i].z--;
		}
		i++;
	}
}

int		key_press(int key, void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	ft_bzero(mlx->data, HEIGHT * WIDTH * (mlx->bbp / 8));
	centering(mlx->img);

	// 126(up arrow), 125(down arrow)
	if (key == UP_ARROW || key == DOWN_ARROW)
		handle_heigth_change(key, mlx);
	else if (key == Q || key == W || key == A || key == S || key == Z || key == X)
		rotate_figure(key, mlx);

	// 49 - change projection

	// 27(-), 24(+) - zoom

	// 53(esc) - quit
	else if (key == 53)
	{
		// terminate()
		exit(1);
	}
	isometry(mlx->img, mlx);
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