/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 16:02:25 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/09/22 14:10:32 by fmasha-h         ###   ########.fr       */
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

typedef	struct	s_img
{
	// t_pix	**pxls;
	// int		size;
    void	*mlx_ptr;
    void	*win_ptr;
    void	*img_ptr;
    int     win_width;
    int     win_height;
    int     img_width;
    int     img_height;
    int     *data;
    int     bbp;
    int     size_line;
    int     endian;

}				t_img;

t_img       	*init_new_img(t_img *new);

#endif