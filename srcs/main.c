/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 16:07:25 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/09/21 20:49:53 by fmasha-h         ###   ########.fr       */
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


int main(int argc, char **argv)
{
	void	*mlx_ptr;
    void	*win_ptr;
	void	*img_ptr;
	char	*data;
	int		*d;
	int	a[4] = {8, 8, 8, 8};
	int	b[3] = {0, 0, 0};
	int	c[1] = {0};


	if (argc > 1 && argv)
	{
		// read_input(argv[1]);

		mlx_ptr = mlx_init();
		win_ptr = mlx_new_window(mlx_ptr, 1000, 1000, "fdf");
		img_ptr = mlx_new_image (mlx_ptr, 1000, 1000);
		data = mlx_get_data_addr(img_ptr, a, b, c);
		ft_printf("%s\n", data);
		d = (int*)data;
		for (int i = 0; i < 100; i++) {
			d[i] = 38 << 16 | 15 << 8 | 212;
		}
		for (int i = 0; i <= 999; i++) {
			mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 0, i + 1);
		}
		mlx_loop(mlx_ptr);
	}
}