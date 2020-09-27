/* 
		TODO

		0. отрефакторить код
		1. потестить парсер и валидатор
		2. обработка клавиш:
			- esc для выхода из программы
			- клавиши +- для зума (колесико мышки)
			- клавиши для изменения высоты
			- стрелки для поворота карты
			- клавиши для смены цвета + сама смена
			- смена проекции
*/

// TODO: change to "fdf.h"
#include "../fdf.h"

void	calc_iso(t_img *img, t_coord *d)
{
	int previous_x;
    int previous_y;

	if (!img)
		return ;
    previous_x = d->x;
    previous_y = d->y;
    d->x = previous_x + (previous_x - previous_y) * cos(0.523599);
    d->y = -d->z + (previous_x + previous_y) * sin(0.523599);
}

void	isometry(t_img *img)
{
	int	i;
	int	j;

	i = 0;
	while (i != img->grid_square)
	{
		j = 0;
		while (j != img->grid_width)
		{
			calc_iso(img, &img->dot[i]);
			j++;
			i++;
		}
	}
}

void	rotate_x(t_coord *d)
{
	int previous_y;
    int previous_z;

    previous_y = (HEIGHT / 100 * 35) -d->y;
	previous_z = d->z;
    d->y = (previous_y) * cos(0.17444) + previous_z * sin(0.17444);
	d->z = (-previous_y) * sin(0.17444) + previous_z * cos(0.17444);
}

void	rotate_figure(int key, t_mlx *mlx)
{
	key = 0;
	int i;

	i = 0;
	while (i < mlx->img->grid_square)
	{
		rotate_x(&(mlx->img->dot[i]));
		i++;
	}
}

int		key_press(int key, void *param)
{
	t_mlx	*mlx;
	int		i;

	mlx = (t_mlx *)param;
	ft_bzero(mlx->data, HEIGHT*WIDTH * (mlx->bbp / 8));
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
	else if (key == 123)
	{
		rotate_figure(key, mlx);
	}
	else if (key == 12 || key == 53)
	{ // press Q to quit
		// terminate()
		exit(1);
	}
	// isometry(mlx->img);
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

int main(int argc, char **argv)
{
	t_mlx	*mlx;

	if (argc > 1 && argv)
	{
		mlx = init_mlx();
		// TODO: create terminate
		// if (img == NULL) {
		// 	terminate()
		// }
		input_processing(argv[1], mlx->img);
		
		centering(mlx->img);
		isometry(mlx->img);
		connect_lines(mlx, mlx->img);
		mlx_put_image_to_window(mlx->ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
		// To handle a key press
		mlx_hook(mlx->win_ptr, 2, 0, key_press, mlx);
		// To handle a red button (X button) press
		mlx_hook(mlx->win_ptr, 17, 0, red_button, mlx);
		mlx_loop(mlx->ptr);
	}
}
