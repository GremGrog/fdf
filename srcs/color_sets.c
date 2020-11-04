/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_sets.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 14:21:10 by yquaro            #+#    #+#             */
/*   Updated: 2020/11/04 14:32:18 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

#define CLR(red, green, blue) (red << 16 | green << 8 | blue)
#define FOREST_COLOR (0 << 16 | 130 << 8 | 0)
#define HILL_COLOR (215 << 16 | 190 << 8 | 0)
#define MOUNTAIN_COLOR (220 << 16 | 120 << 8 | 0)
#define SUPER_MOUNTAIN_COLOR (160 << 16 | 70 << 8 | 0)

#define SET_MARS_COLOR(red, green) (red << 16 | green << 8 | 0)

int			*mars_color_set(t_color *color)
{
	int *color_set;
	int	i;
	int red;
	int green;

	if ((color_set = (int *)malloc(sizeof(int) * MAX_NUMBER_OF_COLORS)) == NULL)
		return (NULL);
	red = 230;
	green = 100;
	i = 0;
	while (i < MAX_NUMBER_OF_COLORS)
	{
		if (color->base_color_index + i < MAX_NUMBER_OF_COLORS)
			color_set[color->base_color_index + i] = ((red < 0 || green < 0) ? \
				CLR(0, 0, 0) : CLR(red, green, 0));
		if (color->base_color_index - i >= 0)
			color_set[color->base_color_index - i] = ((red < 0 || green < 0) ? \
				CLR(0, 0, 0) : CLR(red, green, 0));
		red -= 10;
		green -= 20;
		i++;
	}
	return (color_set);
}

static void	earth_color(t_color *color, int *color_set)
{
	int		i;

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
}

int			*earth_color_set(t_color *color)
{
	int		i;
	int		*color_set;
	int		green;
	int		blue;

	if ((color_set = (int *)malloc(sizeof(int) * MAX_NUMBER_OF_COLORS)) == NULL)
		return (NULL);
	green = 130;
	blue = 255;
	i = color->base_color_index;
	while (i >= 0)
	{
		color_set[i--] = ((blue < 0 || green < 0) ? \
			CLR(0, 0, 0) : CLR(0, green, blue));
		green -= 30;
		blue -= 50;
	}
	earth_color(color, color_set);
	return (color_set);
}

void		apply_color_set(t_mlx *mlx, int *color_set)
{
	size_t	i;
	size_t	j;

	if (color_set == NULL)
		terminate(&mlx);
	i = 0;
	while (i < (size_t)mlx->img->grid_square)
	{
		j = 0;
		while (j < (size_t)mlx->img->color->size && \
			mlx->img->point[i].z >= mlx->img->color->relief_color_borders[j])
		{
			mlx->img->point[i].color = color_set[j];
			j++;
		}
		i++;
	}
	free(color_set);
	color_set = NULL;
}
