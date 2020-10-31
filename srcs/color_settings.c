#include "../fdf.h"

static int	most_frequent_z(t_img *img, int min)
{
	int		meeting[(MAX_Z * 2) + 1];
	int		abs_min_z;
	int		most;
	int		counter_max;
	int		i;

	ft_bzero(meeting, sizeof(int) * (MAX_Z * 2 + 1));
	abs_min_z = abs(min);
	i = 0;
	while (i < img->grid_square)
		meeting[img->point[i++].z + abs_min_z]++;
	i = 0;
	counter_max = 0;
	while (i < (MAX_Z * 2 + 1))
	{
		if (meeting[i] > counter_max)
		{
			most = i - abs_min_z;
			counter_max = meeting[i];
		}
		i++;
	}
	return (most);
}

static void apply_color_set_first(t_mlx *mlx, int *color_set)
{
	int     i;
	int     j;

	if (color_set == NULL)
		terminate(&mlx);
	i = -1;
	while (++i < mlx->img->grid_square)
	{
		if (mlx->img->point[i].color != 0)
			continue ;
		j = 0;
		while (j < mlx->img->color->size && mlx->img->point[i].z >= mlx->img->color->relief_color_borders[j])
			mlx->img->point[i].color = color_set[j++];
	}
	free(color_set);
	color_set = NULL;
}

static int  calculate_relief(t_color *color, int max, int min, int most)
{
	int     step;
	int     border;
	int     j;

	step = ft_ceil((double)(max - min) / MAX_NUMBER_OF_COLORS);
	border = min;
	j = 0;
	while (border < max)
	{
		if (most >= border && most < border + step)
		{
			color->relief_color_borders[j] = most;
			color->base_color_index = j;
		}
		else
			color->relief_color_borders[j] = border;
		border += step;
		j++;
	}
	if (max == most)
		color->base_color_index = j;
	color->relief_color_borders[j] = max;
	return (j);
}

static void	set_bump(t_img *img, int most)
{
	int		i;

	i = 0;
	while (i < img->grid_square)
	{
		if (img->point[i].z != most)
			img->point[i].bump = 1;
		i++;
	}
}

void        setting_parameters(t_mlx *mlx)
{
	int     size;
	int     most;
	int		min;

	if ((mlx->img->color = init_color()) == NULL)
		terminate(&mlx);
	min = min_z(mlx->img);
	most = most_frequent_z(mlx->img, min);
	size = calculate_relief(mlx->img->color, max_z(mlx->img), min, most);
	mlx->img->color->size = size;
	apply_color_set_first(mlx, earth_color_set(mlx->img->color));
	set_bump(mlx->img, most);
}
