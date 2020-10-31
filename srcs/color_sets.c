#include "../fdf.h"

#define SET_OCEAN_COLOR(green, blue) (0 << 16 | green << 8 | blue)
#define FOREST_COLOR (0 << 16 | 130 << 8 | 0)
#define HILL_COLOR (215 << 16 | 190 << 8 | 0)
#define MOUNTAIN_COLOR (220 << 16 | 120 << 8 | 0)
#define SUPER_MOUNTAIN_COLOR (160 << 16 | 70 << 8 | 0)

int			*earth_color_set(t_color *color)
{
	int		i;
	int		*color_set;
	int		green;
	int		blue;

	if ((color_set = (int *)malloc(sizeof(int) * MAX_NUMBER_OF_COLORS)) == NULL)
		return NULL;
	green = 130;
	blue = 255;
	i = color->base_color_index;
	while (i >= 0)
	{
		color_set[i--] = ((blue < 0 || green < 0) ? SET_OCEAN_COLOR(0, 0) : SET_OCEAN_COLOR(green, blue));
		green -= 30;
		blue -= 50;
	}
	i = color->base_color_index + 1;
	if (i < color->size)
		color_set[i++] = FOREST_COLOR;
	if (i < color->size)
		color_set[i++] = HILL_COLOR;
	if (i < color->size)
		color_set[i++] = MOUNTAIN_COLOR;
	if (i < color->size)
		color_set[i++] = SUPER_MOUNTAIN_COLOR;
	while (i < color->size)
		color_set[i++] = WHITE_COLOR;
	return (int *)color_set;
}

void		apply_color_set(t_img *img, int *color_set)
{
	size_t	i;
	size_t	j;

	// if (color_set == NULL)
		// terminate(img);
	i = 0;
	while (i < (size_t)img->grid_square)
	{
		j = 0;
		while (j < (size_t)img->color->size && img->point[i].z >= img->color->relief_color_borders[j])
		{
			img->point[i].color = color_set[j];
			j++;
		}
		i++;
	}
}