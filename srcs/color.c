#include "../fdf.h"

void			change_color_set(t_mlx *mlx)
{
	static int	i = 1;

	if (i == 0)
		apply_color_set(mlx, earth_color_set(mlx->img->color));
	else if (i == 1)
		apply_color_set(mlx, mars_color_set(mlx->img->color));
	i = (i + 1) % NUMBER_OF_COLOR_SETS;
}

static double	percent(int start, int end, int current)
{
	double placement;
	double distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

static int		get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int     get_color(t_point start, t_point end, t_point delta, t_point current)
{
	int		red;
	int		green;
	int		blue;
	double	percentage;

	if (delta.x > delta.y)
		percentage = percent(start.x, end.x, current.x);
	else
		percentage = percent(start.y, end.y, current.y);
	red = get_light((start.color >> 16) & 0xFF,\
			(end.color >> 16) & 0xFF, percentage);
	green = get_light((start.color >> 8) & 0xFF,\
			(end.color >> 8) & 0xFF, percentage);
	blue = get_light(start.color & 0xFF, end.color & 0xFF, percentage);
	return ((red << 16) | (green << 8) | blue);
}
