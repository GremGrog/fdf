#include "../fdf.h"

void	calc_iso(t_coord *d, t_cam *camera)
{
	int previous_x;
    int previous_y;

    previous_x = d->x;
    previous_y = d->y;
    d->x = previous_x + (previous_x + previous_y) * cos(-0.523599);
	if (camera->front == TRUE)
	{
    	d->y = d->z + (previous_x - previous_y) * sin(-0.523599);
	}
	else
	{
		d->y = -d->z + (previous_x - previous_y) * sin(-0.523599);
	}
	
}

void	isometry(t_img *img, t_cam *camera)
{ 
	int	i;

	i = 0;
	while (i < img->grid_square)
	{
		calc_iso(&img->dot[i], camera);
		i++;
	}
}