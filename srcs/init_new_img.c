/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_new_img.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 14:03:42 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/09/30 15:38:51 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_img	*init_new_img(t_img *new)
{
	new->mlx_ptr = NULL;
	new->grid_height = 0;
	new->grid_square = 0;
	new->grid_length = 0;
	new->win_ptr = NULL;
	new->img_ptr = NULL;
	new->win_width = 1500;
	new->win_height = 1500;
	new->img_width = 1500;
	new->img_height = 1500;
	new->data = 0;
	new->bbp = 0;
	new->size_line = 0;
	new->endian = 0;
	return (new);
}