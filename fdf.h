/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 16:02:25 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/09/24 21:07:30 by fmasha-h         ###   ########.fr       */
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
	int		color;
}				t_pix;

typedef	struct	s_img
{
	t_pix	*pxls;
	int		num_of_lines;
	int		dots_num;
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

}					t_img;

t_img			*init_new_img(t_img *new);
void			input_processing(char *str, t_img *img);
int				validate_line(char *line);
void			bresenham_alg(t_img *img);

#endif