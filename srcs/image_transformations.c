#include "../fdf.h"

void	change_projection(t_cam *camera)
{
	if (camera->projection == ISO)
		camera->projection = CENTRAL;
	else if (camera->projection == CENTRAL)
		camera->projection = ISO;
}

void    accept_rotation_to_image(t_mlx *mlx)
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
	if (key == PLUS && mlx->img->margin_x > -100 && mlx->img->margin_y > -100) 
	{
			mlx->img->margin_x -= 10;
			mlx->img->margin_y -= 10;
	}	
	else if (key == MINUS && mlx->img->margin_x < MARGIN_X && mlx->img->margin_y < MARGIN_Y)
	{
			mlx->img->margin_x += 10;
			mlx->img->margin_y += 10;
	}
	centering(mlx->img);
}

void	move_x_asix(t_img *img, int direction)
{
	int i;

	i = 0;
	if (direction == LEFT_DIRECTION && find_rightmost_point(img) <= -WIDTH / 2)
		return;
	if (direction == RIGHT_DIRECTION && find_leftmost_point(img) >= WIDTH / 2)
		return;
	while (i < img->grid_square)
	{
		if (direction == LEFT_DIRECTION)
			img->point[i].x_shift -= 10;
		else if (direction == RIGHT_DIRECTION)
			img->point[i].x_shift += 10;
		i++;
	}
}

void	move_y_asix(t_img *img, int direction)
{
	int i;

	i = 0;
	if (direction == UP_DIRECTION && find_lowest_point(img) >= HEIGHT / 2)
		return;
	if (direction == DOWN_DIRECTION && find_upmost_point(img) <= -HEIGHT / 2)
		return;
	while (i < img->grid_square)
	{
		if (direction == UP_DIRECTION)
			img->point[i].y_shift += 10;
		else if (direction == DOWN_DIRECTION)
			img->point[i].y_shift -= 10;
		i++;
	}
}

void	move_image(int key, t_mlx *mlx)
{
	if (key == LEFT)
		move_x_asix(mlx->img, LEFT_DIRECTION);
	else if (key == RIGHT)
		move_x_asix(mlx->img, RIGHT_DIRECTION);
	else if (key == UP)
		move_y_asix(mlx->img, UP_DIRECTION);
	else if (key == DOWN)
		move_y_asix(mlx->img, DOWN_DIRECTION);
}
