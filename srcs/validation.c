/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 14:46:22 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/09/24 16:26:59 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int		validate_color(char *line, int i)
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
		if (ft_isdigit(line[i]) == 1)
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
