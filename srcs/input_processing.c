/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_processing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 13:34:14 by fmasha-h          #+#    #+#             */
/*   Updated: 2020/11/04 14:40:28 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static int		defer(int fd, char **buf)
{
	if (*buf != NULL)
		free(*buf);
	buf = NULL;
	close(fd);
	return (-1);
}

int				read_input(char *str, t_img *img)
{
	int			fd;
	char		*buf;
	int			point_index;

	point_index = 0;
	fd = open(str, O_RDONLY);
	buf = NULL;
	while (get_next_line(fd, &buf) > 0)
	{
		if (buf)
		{
			if ((point_index = parse_coords_in_line(buf, \
					img->point, img->grid_height, point_index)) == -1)
				return (defer(fd, &buf));
			img->grid_height++;
			free(buf);
			buf = NULL;
		}
	}
	defer(fd, &buf);
	return (0);
}

int				input_processing(char *str, t_mlx *mlx)
{
	int	flag;

	if (count_input_len(str, mlx->img) < 0)
		terminate(&mlx);
	if (!(mlx->img->point = (t_point*)malloc(sizeof(t_point) * \
			mlx->img->grid_square)))
		terminate(&mlx);
	flag = read_input(str, mlx->img);
	if (mlx->img->grid_square % mlx->img->grid_height != 0)
		terminate(&mlx);
	return (flag);
}
