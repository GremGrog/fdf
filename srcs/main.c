/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 16:07:25 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/09/22 21:42:03 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

// void	read_input(char *argv)
// {
// 	int		fd;
// 	char	*buf;
// 	int		line_num;

// 	fd = open(argv, O_RDONLY);
// 	line_num = 0;
// 	while (get_next_line(fd, &buf) > 0)
// 	{
// 		if (validate_line(buf) == 0)
// 		{
// 			line_num++;
			
// 		}
// 	}
// }
void	bresenham_line(t_img *img)
{
	int p1 = 100 * img->img_width + 0;
	int x1 = p1 % img->img_width;
	int y1 = p1 / img->img_height;
	int p2 = 150 * img->img_width + 300;
	int x2 = p2 % img->img_width;
	int y2 = p2 / img->img_height;
	// img->data[p1] = 255 << 16 | 255 << 8 | 255;
	// img->data[p2] = 255 << 16 | 255 << 8 | 255;

	int	deltaX = abs(x2 - x1);
	int	deltaY = abs(y2 - y1);
	int deltaError = (deltaX > deltaY ? deltaX : -deltaY) / 2;
	int error = deltaError;
	int x = x1;
	int	y = y1;
	ft_printf("%d %d %d\n", deltaError, deltaX, deltaY);
	while (1)
	{
		img->data[y * img->img_width + x] = 255 << 16 | 255 << 8 | 255;
		if (x == x2 && y == y2)
			break ;
		error = deltaError;
		if (error > -deltaX)
		{
			deltaError -= deltaY;
			ft_printf("%d\n", deltaError);
			x += (x1 < x2) ? 1 : -1;
		}
		if (error < deltaY)
		{
			deltaError += deltaX;
			ft_printf("Y%d\n", deltaError);
			y += (y1 < y2) ? 1 : -1;
		}
	}
}

int main(int argc, char **argv)
{
	
	t_img	*img;

	if (argc > 1 && argv)
	{
		// read_input(argv[1]);
		img = (t_img*)malloc(sizeof(t_img));
		img = init_new_img(img);
		img->mlx_ptr = mlx_init();
		img->win_ptr = mlx_new_window(img->mlx_ptr, img->win_width, img->win_height, "fdf");
		img->img_ptr = mlx_new_image (img->mlx_ptr, img->img_width, img->img_height);
		img->data = (int*)mlx_get_data_addr(img->img_ptr, &img->bbp, &img->size_line, &img->endian);
		bresenham_line(img);
		mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, img->img_ptr, 0, 0);
		mlx_loop(img->mlx_ptr);
	}
}