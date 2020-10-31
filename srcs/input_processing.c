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

int		read_input(char *str, t_img *img)
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
			if ((point_index = parse_coords_in_line(buf, \
				img->point, img->grid_height, point_index)) == -1)
			{
				close(fd);
				free(buf);
				return (-1);
			}
			img->grid_height++;
			free(buf);
		}
	}
	close(fd);
	return (0);
}

int		input_processing(char *str, t_img *img)
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
	return (read_input(str, img));
}
