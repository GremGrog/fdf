/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 14:46:22 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/09/30 17:12:41 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int		in_hex(char c)
{
	if (ft_isdigit(c) == 1)
		return (1);
	if (c >= 'a' && c <= 'f')
		return (1);
	if (c >= 'A' && c <= 'F')
		return (1);
	return (0);
}

int		validate_color(char *line, int i)
{
	if (line[i] == '0')
	{
		i++;
		if (line[i] == 'x')
		{
			i++;
			if (in_hex(line[i]))
			{
				while (line[i] && (in_hex(line[i])))
					i++;
				return (i);
			}
		}
	}
	return (-1);
}

int		validate_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (ft_isspace(line[i]) == 1)
		{
			if (ft_isspace(line[i + 1] == 1))
				return (-1);
			i++;
		}
		if (ft_isdigit(line[i]) == 1 ||\
					(line[i] == '-' && ft_isdigit(line[i + 1]) == 1))
		{
			i++;
			if (line[i] == ',')
			{
				if ((i = validate_color(line, ++i)) == -1)
					return (-1);
			}
		}
		if (ft_isalpha(line[i]) == 1)
			return (-1);
	}
	return (0);
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
				return (-1);
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
