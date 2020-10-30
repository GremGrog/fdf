/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_processing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 13:34:14 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/10/01 15:51:13 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_point	add_color(char *str, t_point point)
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
			point.color = ft_atoi_base(arr[i], 16);
		else
			point.z = ft_atoi(arr[i]);
		i++;
	}
	del_matrix(arr);
	free(arr);
	return (point);
}

int		add_coords(char *str, t_point **point, int line_num, int point_index)
{
	int		i;
	int		j;
	char	**line;

	i = 0;
	j = point_index;
	line = ft_strsplit(str, ' ');
	while (line[i])
	{
		(*point)[j].x_shift = 0;
		(*point)[j].y_shift = 0;
		(*point)[j].z_shift = 0;
		(*point)[j].x = i;
		(*point)[j].y = line_num;
		if ((char*)ft_strchr(line[i], ',') != NULL)
			(*point)[j] = add_color(line[i], (*point)[j]);
		else
		{
			(*point)[j].z = ft_atoi(line[i]);
			(*point)[j].bump = 0;
			if ((*point)[j].z != 0)
				(*point)[j].bump = 1;
			(*point)[j].color = 25343;
		}
		i++;
		j++;
	}
	del_matrix(line);
	free(line);
	return (j);
}

void	read_input(char *str, t_img *img)
{
	int		fd;
	char	*buf;
	int		point_index;

	point_index = 0;
	fd = open(str, O_RDONLY);
	while (get_next_line(fd, &buf) > 0)
	{
		if (buf)
		{
			point_index = add_coords(buf, \
			&img->point, img->grid_height, point_index);
			img->grid_height++;
			free(buf);
		}
	}
	close(fd);
}

int		count_input_len(char *str, t_img *img)
{
	int		fd;
	char	*buf;
	int		len;
	int		first_line_points_num;

	if ((fd = open(str, O_RDONLY)) < 0)
		return (-1);
	first_line_points_num = -1;
	while (get_next_line(fd, &buf) > 0)
	{
		if (validate_line(buf) == 0 && (len = count_words(buf)) > 0)
		{
			if (first_line_points_num == -1)
				first_line_points_num = len;
			else if (first_line_points_num != len)
				return -1;
			img->grid_square += len;
			free(buf);
		}
		else
			return (-1);
	}
	close(fd);
	set_rotation_step(img);
	return (0);
}

void	input_processing(char *str, t_img *img)
{
	if (!img)
		exit(-1);
	if (count_input_len(str, img) < 0)
	{
		ft_printf("Error\n");
		exit(-1);
	}
	if (!(img->point = (t_point*)malloc(sizeof(t_point) * img->grid_square)))
		exit(-1);
	read_input(str, img);
}
