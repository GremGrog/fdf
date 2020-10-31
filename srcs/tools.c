#include "../fdf.h"

int			ft_ceil(double num)
{
	if (num - (int)num != 0.0)
		return (int)num + 1;
	return (int)num;
}

int			max_z(t_img *img)
{
	int     i;
	int     max_z;

	max_z = img->point[0].z;
	i = 0;
	while (i < img->grid_square)
	{
		if (img->point[i].z > max_z)
			max_z = img->point[i].z;
		i++;
	}
	return max_z;
}

int         min_z(t_img *img)
{
	int     i;
	int     min_z;

	min_z = img->point[0].z;
	i = 0;
	while (i < img->grid_square)
	{
		if (img->point[i].z < min_z)
			min_z = img->point[i].z;
		i++;
	}
	return min_z;
}