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

int	key_press(int key, t_mlx *mlx, t_img *img)
{
	int		i;

	if (key == 126) {
		i = 0;
		while (i < img->grid_square)
		{
			if (img->dot[i].z != 0)
				img->dot[i].z++;
			i++;
		}
	} else if (key == 125)
	{
		i = 0;
		while (i < img->grid_square)
		{
			if (img->dot[i].z != 0)
			{
				img->dot[i].z--;
				if (img->dot[i].z == 0)
					img->dot[i].z--;
			}
			i++;
		}
	}
	ft_bzero(mlx->data, HEIGHT*WIDTH * (mlx->bbp / 8));
	calculate_coords(img);
	isometry(img);
	connect_lines(mlx, img);
	mlx_put_image_to_window(mlx->ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
	return 0;
}

int main(int argc, char **argv)
{
	t_img	*img;
	t_mlx	*mlx;

	if (argc > 1 && argv)
	{
		img = init_img();
		// TODO: create terminate
		// if (img == NULL) {
		// 	terminate()
		// }
		input_processing(argv[1], img);

		mlx = init_mlx();
		// TODO: create terminate
		// if (mlx == NULL) {
		// 	terminate()
		// }
		
		calculate_coords(img);
		isometry(img);
		connect_lines(mlx, img);
		mlx_put_image_to_window(mlx->ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
		mlx_hook(mlx->win_ptr, 2, 0, key_press, mlx);
		mlx_loop(mlx->ptr);
	}
}