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

t_coord	add_color(char *str, t_coord dot)
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
			dot.color = ft_atoi_base(arr[i], 16);
		else
			dot.z = ft_atoi(arr[i]);
		i++;
	}
	del_matrix(arr);
	free(arr);
	return (dot);
}

int		add_coords(char *str, t_coord **dot, int line_num, int dot_index)
{
	int		i;
	int		j;
	char	**line;

	i = 0;
	j = dot_index;
	line = ft_strsplit(str, ' ');
	while (line[i])
	{
		(*dot)[j].x = i;
		(*dot)[j].y = line_num;
		if ((char*)ft_strchr(line[i], ',') != NULL)
			(*dot)[j] = add_color(line[i], (*dot)[j]);
		else
		{
			(*dot)[j].z = ft_atoi(line[i]);
			(*dot)[j].bump = 0;
			if ((*dot)[j].z != 0)
				(*dot)[j].bump = 1;
			(*dot)[j].color = 25343;
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
	int		dot_index;

	dot_index = 0;
	fd = open(str, O_RDONLY);
	while (get_next_line(fd, &buf) > 0)
	{
		if (buf)
		{
			dot_index = add_coords(buf, \
			&img->dot, img->grid_height, dot_index);
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

	// TODO: protect open
	fd = open(str, O_RDONLY);
	while (get_next_line(fd, &buf) > 0)
	{
		if (validate_line(buf) == 0 && (len = count_words(buf)) > 0)
		{
			img->grid_square += len;
			free(buf);
		}
		else
			return (-1);
	}
	close(fd);
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
	// TODO: protect malloc
	img->dot = (t_coord*)malloc(sizeof(t_coord) * img->grid_square);
	read_input(str, img);
}
