#include "../fdf.h"

void	calc_iso(t_coord *d)
{
	int previous_x;
    int previous_y;

    previous_x = d->x;
    previous_y = d->y;
    d->x = previous_x + (previous_x + previous_y) * cos(ft_radian(-30));
    d->y = d->z + (previous_x - previous_y) * sin(ft_radian(-30));
}

void	isometry(t_img *img)
{ 
	int	i;

	i = 0;
	while (i < img->grid_square)
	{
		calc_iso(&img->dot[i]);
		i++;
	}
}
