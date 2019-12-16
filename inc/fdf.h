/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 09:40:26 by yquaro            #+#    #+#             */
/*   Updated: 2019/12/16 16:24:26 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/includes/libft.h"
# include "mlx.h"
# include <math.h>

typedef struct  s_pix
{
	int 		x;
	int 		y;
	int 		z;
	long		color;
}				t_pix;

typedef struct	s_fdfmap
{
	size_t		num_of_lines;
	size_t		dots_per_line;
	size_t		dots_num;
}				t_fdfmap;

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	size_t		win_width;
	size_t		win_height;
	size_t		img_width;
	size_t		img_height;
	int     	*data;
	int    	 	bbp;
	int     	size_line;
	int    		endian;
}				t_mlx;

typedef	struct	s_window
{
	t_pix		*pxls;
	t_fdfmap	map;
	t_mlx		*mlx;
}				t_window;


void				mlx_delete(t_window **window);
t_window			*mlx_initialization(char **argv);
void				input_processing(char *str, t_window *window);
void				calculate_coords(t_window *window);
void				connect_lines(t_window *window);

#endif