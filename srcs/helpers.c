#include "../fdf.h"

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

void	copy_point(t_point *point1, t_point *point2)
{
	point1->x = point2->x;
	point1->y = point2->y;
	point1->z = point2->z;
	point1->color = point2->color;
	point1->z_shift = point2->z_shift;
	point1->bump = point2->bump;
}

void	save_defaults(t_img *img)
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