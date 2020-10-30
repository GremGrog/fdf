#include "../fdf.h"

void	handle_heigth_change(int key, t_mlx *mlx)
{
	int i;

	i = 0;
	while (i < mlx->img->grid_square)
	{
		if (mlx->img->point[i].bump == TRUE)
		{
			if (key == R && mlx->img->point[i].z_shift <= MAX_HEIGHT)
			{
				mlx->img->point[i].z++;
				mlx->img->point[i].z_shift++;
			}
			else if (key == F && mlx->img->point[i].z_shift >= -MAX_HEIGHT)
			{
				mlx->img->point[i].z--;
				mlx->img->point[i].z_shift--;
			}
		}
		i++;
	}
}

void	other_keys_presses(int key, t_mlx *mlx)
{
	if (key == DELETE)
		reset_all(mlx);
	else if (key == ESC)
	{
		terminate(mlx);
		exit(1);
	}
	else if (key == PLUS || key == MINUS)
		zoom(key, mlx);
	else if (key == L)
		change_color_pair();
	else if (key == UP || key == DOWN || key == LEFT || key == RIGHT)
		move_image(key, mlx);
}

int		key_press(int key, void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	ft_bzero(mlx->data, HEIGHT * WIDTH * (mlx->bbp / 8));
	centering(mlx->img);
	if (key == R || key == F)
		handle_heigth_change(key, mlx);
	else if (key == Q || key == W || key == A ||\
										key == S || key == Z || key == X)
		rotate_figure(key, mlx);
	else if (key == SPACE)
		change_projection(mlx->img->camera);
	else
		other_keys_presses(key, mlx);
	if (mlx->img->camera->projection == ISO)
		isometry(mlx->img);
	accept_rotation_to_image(mlx);
	connect_lines(mlx, mlx->img);
	mlx_put_image_to_window(mlx->ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
	return (0);
}

int		red_button(void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	terminate(mlx);
	exit(1);
}
