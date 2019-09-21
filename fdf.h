/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 16:02:25 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/09/21 17:21:46 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "Libft/libft.h"
# include "mlx.h"
# include <math.h>

typedef struct  s_pix
{
    int 	x;
    int 	y;
    int 	z;
}				t_pix;

typedef	struct	s_map
{
	t_pix	**pxls;
	int		size;
}				t_map;

#endif