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

void	calc_iso(t_img *img, t_pix *d)
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
	j = 0;
	while (i != img->grid_square)
	{
		j = 0;
		while (j != img->grid_length)
		{
			calc_iso(img, &img->pxls[i]);
			j++;
			i++;
		}
	}
} 

// int	key_press(int key, void *param)
// {
// 	t_img	*img;

// 	img = (t_img *)param;

// 	if (key == 126) {
// 		int i = 0;
// 		while (i < img->grid_square) {
// 			int j = 0;
// 			while (j < img->grid_length) {
				
// 			}
// 		}
// 	}
// }

int main(int argc, char **argv)
{
	t_img	*img;

	if (argc > 1 && argv)
	{
		img = (t_img*)malloc(sizeof(t_img));
		img = init_new_img(img);
		input_processing(argv[1], img);
		img->mlx_ptr = mlx_init();
		img->win_ptr = mlx_new_window(img->mlx_ptr, img->win_width, img->win_height, "fdf");
		img->img_ptr = mlx_new_image (img->mlx_ptr, img->img_width, img->img_height);

		// TODO play with bbp value
		img->data = (int*)mlx_get_data_addr(img->img_ptr, &img->bbp, &img->size_line, &img->endian);
		
		calculate_coords(img);
		// isometry(img);
		connect_lines(img);
		mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, img->img_ptr, 0, 0);
		// mlx_hook(img->win_ptr, 2, 0, key_press, img);
		mlx_loop(img->mlx_ptr);
	}
}