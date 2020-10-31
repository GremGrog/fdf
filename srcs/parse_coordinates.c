
#include "../fdf.h"

static int defer(char ***line)
{
	if (*line != NULL)
	{
		del_matrix(*line);
		free(*line);
	}
	*line = NULL;
	return (-1);
}

void	add_color(char *str, t_point *point)
{
	char	**arr;
	char	*buf;
	int		i;

	i = 0;
	arr = ft_strsplit(str, ',');
	buf = NULL;
	while (arr[i])
	{
		if ((buf = ft_strchr(arr[i], 'x')) != NULL)
			(point)->color = ft_atoi_base(arr[i], 16);
		else
			(point)->z = ft_atoi(arr[i]);
		i++;
	}
	defer(&arr);
}

void	add_coordinate(t_point *point, int i, int line_num, char *line)
{
	if (!line || line_num < 0 || i < 0)
		return ;
	point->x_shift = 0;
	point->y_shift = 0;
	point->z_shift = 0;
	point->bump = 0;
	point->color = 0;
	point->x = i;
	point->y = line_num;
	if ((char*)ft_strchr(line, ',') != NULL)
		add_color(line, point);
	else
		point->z = ft_atoi(line);
}

int		check_z_height(t_point *point)
{
	if (abs(point->z) > MAX_Z)
		return (-1);
	return (0);
}

int		parse_coords_in_line(char *str, t_point *point,\
			int line_num, int point_index)
{
	int		i;
	int		j;
	char	**line;

	i = 0;
	j = point_index;
	line = ft_strsplit(str, ' ');
	while (line[i])
	{
		add_coordinate(&point[j], i, line_num, line[i]);
		if ((check_z_height(&point[j])) < 0)
			return (defer(&line));
		i++;
		j++;
	}
	defer(&line);
	return (j);
}
