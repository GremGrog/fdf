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
// # include "mlx.h"
# include "/usr/X11/include/mlx.h"

# define WIDTH 1500
// # define WIDTH 1200
// # define HEIGHT 1500
# define HEIGHT 1200
# define WINDOW_NAME "fdf"

# define ROTATION_STEP 0.02
# define MAX_HEIGHT 50

# define TRUE 1
# define FALSE 0
# define ISO 111
# define CENTRAL 222
# define Q 12
# define W 13
# define A 0
# define S 1
# define Z 6
# define X 7

// change color pair
# define L 37

// change height
# define R 15
# define F 3

# define SPACE 49
# define ESC 53

# define YELLOW_COLOR (255 << 16 | 255 << 8 | 0)
# define PINK_COLOR (255 << 16 | 0 << 8 | 150)
# define PURPLE_COLOR (97 << 16 | 0 << 8 | 144)
# define GREEN_COLOR (0 << 16 | 255 << 8 | 0)
# define BLUE_COLOR (0 << 16 | 0 << 8 | 255)
# define RED_COLOR (255 << 16 | 97 << 8 | 97)

# define NUMBER_OF_COLOR_PAIRS 4

typedef struct  s_coord
{
	int 	x;
	int 	y;
	int 	z;
	int		z_shift;
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
	int		projection;
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

typedef struct s_colorpair
{
	int			base;
	int			bump;
}				t_colorpair;

t_colorpair		g_color_pair;

t_img			*init_img();
t_mlx			*init_mlx();
void			input_processing(char *str, t_img *img);
int				validate_line(char *line);

int				get_color(t_coord start, t_coord end, t_coord delta, t_coord current);
void        	change_color_pair(void);

void    		check_image_front(t_cam *camera);
double  		convert_degree(double degree);
int				key_press(int key, void *param);
int				red_button(void *param);

void			centering(t_img *img);
void			bresenham_alg(t_mlx *mlx, t_coord d1, t_coord d2);
void			connect_lines(t_mlx *mlx, t_img *img);

void			rotate_x(t_coord *d, t_cam *camera);
void			rotate_y(t_coord *d, t_cam *camera);
void			rotate_z(t_coord *d, t_cam *camera);

void			isometry(t_img *img);
void			rotate_figure(int key, t_mlx *mlx);

double			ft_radian(double degree);

#endif