/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 13:46:38 by yquaro            #+#    #+#             */
/*   Updated: 2019/12/16 18:53:25 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int				validate_color(char *line, int i)
{
	if (line[i] == '0')
	{
		i++;
		if (line[i] == 'x')
		{
			i++;
			if (ft_isdigit(line[i]) == 1 || (line[i] >= 'a' && line[i] <= 'f'))
			{
				while (line[i] && (ft_isdigit(line[i]) == 1 ||
						(line[i] >= 'a' && line[i] <= 'f')))
					i++;
				return (i);
			}
		}
	}
	return (-1);
}

static int				validate_line(char *line)
{
	int					i;

	i = 0;
	while (line[i])
	{
		if (ft_isspace(line[i]) == 1)
		{
			if (ft_isspace(line[i + 1] == 1))
				return (-1);
			i++;
		}
		if (ft_isdigit(line[i]) == 1 || (line[i] == '-' && ft_isdigit(line[i + 1]) == 1))
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

static t_pix			add_color(char *str, t_pix dot)
{
	char				**arr;
	int					i;

	i = 0;
	arr = ft_strsplit(str, ',');
	while (arr[i])
	{
		if (ft_strchr(arr[i], 'x') != NULL)
			dot.color = ft_atoi_base(arr[i], 16);
		else
			dot.z = ft_atoi(arr[i]);
		i++;
	}
	ft_matrdel(&arr);
	return (dot);
}

static int			add_coords(char *str, t_pix **pxls, \
						int line_num, int dot_index)
{
	int				i;
	int				j;
	char			**line;

	i = 0;
	j = dot_index;
	// ft_printf("|%s|\n\n", str);
	line = ft_strsplit(str, ' ');
	while (line[i])
	{
		(*pxls)[j].x = i;
		(*pxls)[j].y = line_num;
		if (ft_strchr(line[i], ',') != NULL)
			(*pxls)[j] = add_color(line[i], (*pxls)[j]);
		else
		{
			(*pxls)[j].z = ft_atoi(line[i]);
			(*pxls)[j].color = 25343;
		}
		i++;
		j++;
	}
	// ft_printf("delete |%s|\n\n", str);
	ft_matrdel(&line);
	return (j);
}

static void			read_input(char *str, t_window *window)
{
	int				fd;
	char			*buf;
	int				dot_index;

	dot_index = 0;
	fd = open(str, O_RDONLY);
	buf = NULL;
	while (get_next_line(fd, &buf) > 0)
	{
		if (buf)
		{
			dot_index = add_coords(buf,	&(window->pxls), \
				window->map.num_of_lines, dot_index);
			window->map.num_of_lines++;
		}
	}
	ft_strdel(&buf);
	close(fd);
}

static int			count_words(char *str)
{
	int				i;
	int				w;
	char			*trim;

	if (!str)
		return (-1);
	i = 0;
	w = 0;
	trim = ft_strtrim(str);
	while (trim[i])
	{
		if (trim[i] && ft_isalnum(trim[i]) == 0 && trim[i] != ',' && trim[i] != '-')
		{
			while (ft_isspace(trim[i]) == 1)
				i++;
			w++;
		}
		i++;
	}
	if (i != 0)
		w++;
	ft_strdel(&trim);
	return (w);
}

static int			count_input_len(char *str, t_window *window)
{
	int				fd;
	char			*buf;
	int				len;

	fd = open(str, O_RDONLY);
	buf = NULL;
	while (get_next_line(fd, &buf) > 0)
	{
		if (validate_line(buf) == 0 && (len = count_words(buf)) > 0)
			window->map.dots_num += len;
		else
			return (-1);
	}
	ft_strdel(&buf);
	close(fd);
	return (0);
}

void				input_processing(char *str, t_window *window)
{
	if (!window)
		exit(-1);
	if (count_input_len(str, window) < 0)
	{
		ft_printf("Error\n");
		exit(-1);
	}
	if ((window->pxls = (t_pix*)malloc(sizeof(t_pix) * window->map.dots_num)) == NULL)
		exit(-1);
	read_input(str, window);
}
