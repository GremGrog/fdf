/* 
		TODO

		0. отрефакторить код
		1. потестить парсер и валидатор

		2. написать функцию сброса к дефолтным значениям
		3. написать функцию пересчета ширины и высоты куба после зума
		4. написать функцию применения поворотов
		5. написать функцию перемещения картинки

*/

// TODO: change to "fdf.h"
#include "../fdf.h"

void	set_default(t_img *img)
{
	int i;
	t_point	*arr;

	i = 0;
	arr = (t_point*)malloc((sizeof(t_point) * img->grid_square));
	while(i < img->grid_square)
	{
		arr[i] = img->point[i];
		i++;
	}
	img->reset_point = arr;
}

void	reset(t_mlx *mlx)
{
	int i;

	i = 0;
	
	while(i < mlx->img->grid_square)
	{
		mlx->img->point[i] = mlx->img->reset_point[i];
		i++;
	}
	mlx->img->camera->alpha = 0;
	mlx->img->camera->beta = 0;
	mlx->img->camera->gamma = 0;
	mlx->img->margin_x = MARGIN_X;
	mlx->img->margin_y = MARGIN_Y;
}


double	ft_radian(double degree)
{
	return degree * 3.14 / 180;
}

double  convert_degree(double degree)
{
    if (degree < 0)
        return degree + 360.0;
    return degree;
}

void    check_image_front(t_cam *camera)
{
	if (convert_degree(camera->alpha) >= 90.0 && convert_degree(camera->alpha) < 270.0)
		camera->front = FALSE;
	else
		camera->front = TRUE;
}


int main(int argc, char **argv)
{
	t_mlx	*mlx;

	if (argc > 1 && argv)
	{
		change_color_pair();
		mlx = init_mlx();

		// TODO: create terminate
		// if (img == NULL) {
		// 	terminate()
		// }
		input_processing(argv[1], mlx->img);

		setting_color_parameters(mlx->img);

		centering(mlx->img);
		set_default(mlx->img);
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
