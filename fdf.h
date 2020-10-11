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
# include <math.h>
# include "/usr/X11/include/mlx.h"

// # define WIDTH 1500
# define WIDTH 1200
// # define HEIGHT 1500
# define HEIGHT 1000
# define WINDOW_NAME "fdf"

# define TRUE 1
# define FALSE 0

typedef struct  s_coord
{
	int 	x;
	int 	y;
	int 	z;
	long	color;
	int		bump;
}				t_coord;

typedef	struct	s_img
{
	t_coord	*dot;
	int		grid_square;
	int		grid_height;
	int		grid_width;
}					t_img;

typedef struct	s_cam
{
	double	alpha;
	double	beta;
	double	gamma;
	int		front;
}					t_cam;

typedef struct	s_mlx
{
	t_img	*img;
	t_cam	*camera;
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

void    		check_image_front(t_cam *camera);
double  		convert_degree(double degree);
int				key_press(int key, void *param);
int				red_button(void *param);

void			centering(t_img *img);
void			bresenham_alg(t_mlx *mlx, t_coord d1, t_coord d2);
void			connect_lines(t_mlx *mlx, t_img *img);

void			isometry(t_img *img);
void			rotate_figure(int key, t_mlx *mlx);

double			ft_radian(double degree);

#endif