#include "../fdf.h"

void	change_projection(t_cam *camera)
{
	if (camera->projection == ISO)
		camera->projection = CENTRAL;
	else if (camera->projection == CENTRAL)
		camera->projection = ISO;
}

void	accept_rotation_to_image(t_mlx *mlx)
{
	int	i;

	i = 0;
	while (i < mlx->img->grid_square)
	{
		rotate_x(&(mlx->img->point[i]), mlx->img->camera);
		rotate_y(&(mlx->img->point[i]), mlx->img->camera);
		rotate_z(&(mlx->img->point[i]), mlx->img->camera);
		i++;
	}
}

void	zoom(int key, t_mlx *mlx)
{
	if (key == PLUS && mlx->img->margin_x > -100 &&\
									mlx->img->margin_y > -100)
	{
		mlx->img->margin_x -= 10;
		mlx->img->margin_y -= 10;
	}
	else if (key == MINUS && mlx->img->margin_x <\
						MARGIN_X && mlx->img->margin_y < MARGIN_Y)
	{
		mlx->img->margin_x += 10;
		mlx->img->margin_y += 10;
	}
	centering(mlx->img);
}
