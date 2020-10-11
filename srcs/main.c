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


double	ft_radian(double degree)
{
	return degree * 3.14 / 180;
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
		isometry(mlx->img, mlx->camera);
		connect_lines(mlx, mlx->img);
		mlx_put_image_to_window(mlx->ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);

		// To handle a key press
		mlx_hook(mlx->win_ptr, 2, 0, key_press, mlx);
		
		// To handle a red button (X button) press
		mlx_hook(mlx->win_ptr, 17, 0, red_button, mlx);


		mlx_loop(mlx->ptr);
	}
}
