/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_controls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaaita <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 22:54:14 by fmaaita           #+#    #+#             */
/*   Updated: 2025/01/15 22:54:22 by fmaaita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_close(t_info *data)
{
	if (data->img.buffer)
		mlx_destroy_image(data->mlx_ptr, data->img.img_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_loop_end(data->mlx_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
	return (0);
}

int	key_handler(int key, t_info *data)
{
	if (key == XK_Escape)
		ft_close(data);
	return (0);
}

int	mouse_handler(int code, int x, int y, t_info *data)
{
	if (code == 4)
	{
		data->fractal.zoom += 2;
		data->fractal.offset_x = ((data->mx + data->fractal.offset_x)
				/ data->width / data->fractal.zoom);
		data->fractal.offset_y = ((data->my + data->fractal.offset_y)
				/ data->width / data->fractal.zoom);
	}
	else if (code == 5 && data->fractal.zoom - 1)
	{
		data->fractal.zoom -= 2;
		data->fractal.offset_x = ((data->mx + data->fractal.offset_x)
				/ data->width / data->fractal.zoom);
		data->fractal.offset_y = ((data->my + data->fractal.offset_y)
				/ data->width / data->fractal.zoom);
	}
	x += y;
	(void)code;
	return (0);
}
