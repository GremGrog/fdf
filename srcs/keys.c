#include "../fdf.h"

void	handle_heigth_change(int key, t_mlx *mlx)
{
	int i;

	i = 0;
	while (i < mlx->img->grid_square)
	{
		if (mlx->img->point[i].bump)
		{
			if (key == R && mlx->img->point[i].z_shift <= MAX_SHIFT_HEIGHT) 
			{
				mlx->img->point[i].z++;
				mlx->img->point[i].z_shift++;
			}
			else if (key == F && mlx->img->point[i].z_shift >= -MAX_SHIFT_HEIGHT)
			{
				mlx->img->point[i].z--;
				mlx->img->point[i].z_shift--;
			}
		}
		i++;
	}
}

void	change_projection(t_cam *camera)
{
	if (camera->projection == ISO)
		camera->projection = CENTRAL;
	else if (camera->projection == CENTRAL)
		camera->projection = ISO;
}

int		key_press(int key, void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	ft_bzero(mlx->data, HEIGHT * WIDTH * (mlx->bbp / 8));
	centering(mlx->img);
	if (key == R || key == F)
		handle_heigth_change(key, mlx);
	else if (key == Q || key == W || key == A || key == S || key == Z || key == X)
		rotate_figure(key, mlx);
	else if (key == SPACE)
		change_projection(mlx->img->camera);
	else if (key == L)
		change_color_pair();
	else if (key == DELETE)
		reset(mlx);
	else if (key == ESC)
	{
		// terminate()
		exit(1);
	}
	else if (key == PLUS) {
		if (mlx->img->margin_x > -100 && mlx->img->margin_y > - 100) 
		{
			mlx->img->margin_x -= 10;
			mlx->img->margin_y -= 10;
		}
	}
	else if (key == MINUS) {
		if (mlx->img->margin_x < 400 && mlx->img->margin_y < 400) {
			mlx->img->margin_x += 10;
			mlx->img->margin_y += 10;
		}
	}
	if (mlx->img->camera->projection == ISO)
		isometry(mlx->img);
	
	
	// TODO 

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