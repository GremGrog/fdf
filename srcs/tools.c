/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 14:40:32 by yquaro            #+#    #+#             */
/*   Updated: 2020/11/04 14:47:12 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int			ft_isdigit_not_zero(int c)
{
	if (c >= '1' && c <= '9')
		return (1);
	else
		return (0);
}

int			in_hex(char c)
{
	if (ft_isdigit(c) == 1)
		return (1);
	if (c >= 'a' && c <= 'f')
		return (1);
	if (c >= 'A' && c <= 'F')
		return (1);
	return (0);
}

int			ft_ceil(double num)
{
	if (num - (int)num != 0.0)
		return (int)num + 1;
	return ((int)num);
}

int			max_z(t_img *img)
{
	int		i;
	int		max_z;

	max_z = img->point[0].z;
	i = 0;
	while (i < img->grid_square)
	{
		if (img->point[i].z > max_z)
			max_z = img->point[i].z;
		i++;
	}
	return (max_z);
}

int			min_z(t_img *img)
{
	int		i;
	int		min_z;

	min_z = img->point[0].z;
	i = 0;
	while (i < img->grid_square)
	{
		if (img->point[i].z < min_z)
			min_z = img->point[i].z;
		i++;
	}
	return (min_z);
}
