/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 16:02:25 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/09/25 19:01:48 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "Libft/libft.h"
# include "mlx.h"
# include <math.h>

# define WIDTH 1500
# define HEIGHT 1500
# define WINDOW_NAME "fdf"

typedef struct  s_coord
{
	int 	x;
	int 	y;
	int 	z;
	long	color;
}				t_coord;

// TODO: move to the s_mlx
typedef	struct	s_img
{
	t_coord	*dot;
	int		grid_square;
	int		grid_height;
	int		grid_width;
}					t_img;

typedef struct	s_mlx
{
	void	*ptr;
	void	*win_ptr;
	void	*img_ptr;
	int     *data;
	int     bbp;
	int     size_line;
	int     endian;
}					t_mlx;

t_img			*init_img();
t_mlx			*init_mlx();
void			input_processing(char *str, t_img *img);
int				validate_line(char *line);

void			calculate_coords(t_img *img);
void			bresenham_alg(t_mlx *mlx, t_coord d1, t_coord d2);
void			connect_lines(t_mlx *mlx, t_img *img);

int				key_press(int key, t_mlx *mlx, t_img *img);

#endif