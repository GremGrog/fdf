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
	return most;
}

static void apply_color_set_first(t_img *img, int *color_set)
{
	int     i;
	int     j;

	// if (color_set == NULL)
		// terminate(img);

	ft_printf("color_set: ");
	int b = 0;
	while (b < MAX_NUMBER_OF_COLORS)
	{
		ft_printf("%d ", color_set[b]);
		b++;
	}
	ft_printf("\n");
	
	i = -1;
	while (++i < img->grid_square)
	{
		if (img->point[i].color != 0)
			continue ;
		j = 0;
		while (j < img->color->size && img->point[i].z >= img->color->relief_color_borders[j])
			img->point[i].color = color_set[j++];
	}
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
	return j;
}

static void	set_bump(t_img *img, int most)
{
	int		i;

	i = 0;
	while(i < img->grid_square)
	{
		if (img->point[i].z != most)
			img->point[i].bump = 1;
		i++;
	}
}

void        setting_parameters(t_img *img)
{
	int     size;
	int     most;
	int		min;

	img->color = init_color();
	// if ((img->color = init_color()) == NULL)
		// terminate(img);
	min = min_z(img);
	most = most_frequent_z(img, min);
	size = calculate_relief(img->color, max_z(img), min, most);
	img->color->size = size;
	apply_color_set_first(img, earth_color_set(img->color));
	set_bump(img, most);
}
