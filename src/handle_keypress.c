/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keypress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 18:21:55 by yquaro            #+#    #+#             */
/*   Updated: 2019/12/17 14:19:07 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int					key_press(int keycode, void *param)
{
	if (keycode == KEY_ESC)
		exit(0);
	return (1);
}

void				setup_controls(t_window *window)
{
	mlx_hook(window->mlx->win_ptr, 2, 0, key_press, window);
}
