/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_processing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 13:34:14 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/09/25 14:02:06 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

// void	add_color(char **buf, t_pix dot)
// {
	
// }

int		add_coords(char *str, t_pix **pxls, int line_num, int dot_index)
{
	int		i;
	int		j;
	char	**line;

	i = 0;
	j = dot_index;
	if (!str)
		return (-1);
	line = ft_strsplit(str, ' ');
	while (line[i])
	{
		(*pxls)[j].x = i;
		(*pxls)[j].y = line_num;
		// if (ft_strchr(line[i], ',') != NULL)
		// 	add_color(line[i], (*pxls)[j]);
		// else
			(*pxls)[j].z = ft_atoi(line[i]);
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
		dot_index = add_coords(buf, &img->pxls, img->num_of_lines, dot_index);
		img->num_of_lines++;
	}
	close(fd);
}

int		count_input_len(char *str, t_img *img)
{
	int		fd;
	char	*buf;
	int		len;

	fd = open(str, O_RDONLY);
	while (get_next_line(fd, &buf) > 0)
	{
		if (validate_line(buf) == 0 && (len = count_words(buf)) > 0)
			img->dots_num += len;
		else
			return (-1);
	}
	close(fd);
	return (0);
}

void	input_processing(char *str, t_img *img)
{
	if (!img)
		exit (-1);
	
	if (count_input_len(str, img) < 0)
	{
		ft_printf("Error\n");
		exit (-1);
	}
	img->pxls = (t_pix*)malloc(sizeof(t_pix) * img->dots_num);
	read_input(str, img);
	for (int i = 0; i < img->dots_num; i++)
	{
		ft_printf("x - %d, y - %d, z - %d\n", img->pxls[i].x, img->pxls[i].y, img->pxls[i].z);
	}
}