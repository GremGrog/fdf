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

// # define WIDTH 1500

# define WIDTH 1200

// # define HEIGHT 1500
# define HEIGHT 800
# define WINDOW_NAME "fdf"
# define RESOLUTION WIDTH * HEIGHT

# define BASIC_ROTATION_STEP 0.02
# define MAX_HEIGHT 50

# define MARGIN_Y (HEIGHT / 100 * 35)
# define MARGIN_X (WIDTH / 100 * 35)

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
# define PLUS 24
# define MINUS 27
# define DELETE 51
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define LEFT_DIRECTION -1
# define RIGHT_DIRECTION 1
# define UP_DIRECTION 2
# define DOWN_DIRECTION -2

# define L 37

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

typedef struct		s_point
{
	int		x;
	int		y;
	int		z;
	int		x_shift;
	int		y_shift;
	int		z_shift;
	long	color;
	int		bump;
}					t_point;

typedef struct		s_cam
{
	double	alpha;
	double	beta;
	double	gamma;
	int		front;
	int		projection;
}					t_cam;

typedef	struct		s_img
{
	t_point	*point;
	t_point	*reset_point;
	t_cam	*camera;
	int		grid_square;
	int		grid_height;
	int		grid_width;
	int		cube_width;
	int		cube_height;
	int		margin_x;
	int		margin_y;
	double	rotation_step;
}					t_img;

typedef struct		s_mlx
{
	t_img	*img;
	void	*ptr;
	void	*win_ptr;
	void	*img_ptr;
	int		*data;
	int		bbp;
	int		size_line;
	int		endian;
}					t_mlx;

typedef struct		s_colorpair
{
	int		base;
	int		bump;
}					t_colorpair;

t_colorpair			g_color_pair;

t_img				*init_img();
t_mlx				*init_mlx();
int					input_processing(char *str, t_img *img);
int					validate_line(char *line);

void				set_rotation_step(t_img *img);

int					get_color(t_point start, t_point end,\
										t_point delta, t_point current);
void				change_color_pair(void);

void				check_image_front(t_cam *camera);
double				convert_degree(double degree);
int					key_press(int key, void *param);
int					red_button(void *param);

void				centering(t_img *img);
void				bresenham_alg(t_mlx *mlx, t_point d1, t_point d2);
void				connect_lines(t_mlx *mlx, t_img *img);

void				rotate_x(t_point *d, t_cam *camera);
void				rotate_y(t_point *d, t_cam *camera);
void				rotate_z(t_point *d, t_cam *camera);

void				isometry(t_img *img);
void				rotate_figure(int key, t_mlx *mlx);

double				ft_radian(double degree);
void				reset_all(t_mlx *mlx);
void				accept_rotation_to_image(t_mlx *mlx);
void				save_defaults(t_img *img);
void				change_projection(t_cam *camera);
void				reset_to_default_coords(t_mlx *mlx);
void				copy_point(t_point *point1, t_point *point2);
void				zoom(int key, t_mlx *mlx);
void				terminate(t_mlx *mlx);
void				move_image(int key, t_mlx *mlx);
int					find_upmost_point(t_img *img);
int					find_lowest_point(t_img *img);
int					find_leftmost_point(t_img *img);
int					find_rightmost_point(t_img *img);
int					count_input_len(char *str, t_img *img);
int					parse_coords_in_line(char *str, t_point *point,\
										int line_num, int point_index);

#endif
