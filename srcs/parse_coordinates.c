
#include "../fdf.h"

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
	del_matrix(arr);
	free(arr);
}

void	add_coordinate(t_point *point, int i, int line_num, char *line)
{
	if (!line || line_num < 0 || i < 0)
		return ;
	point->x_shift = 0;
	point->y_shift = 0;
	point->z_shift = 0;
	point->x = i;
	point->y = line_num;
	if ((char*)ft_strchr(line, ',') != NULL)
		add_color(line, point);
	else
	{
		point->z = ft_atoi(line);
		point->bump = 0;
		if (point->z != 0)
			point->bump = 1;
		point->color = 25343;
	}
}

int		check_z_height(t_point *point)
{
	if (point->z > MAX_HEIGHT)
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
		{
			del_matrix(line);
			free(line);
			return (-1);
		}
		i++;
		j++;
	}
	del_matrix(line);
	free(line);
	return (j);
}
