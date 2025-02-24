/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaaita <fmaaita@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 22:52:03 by fmaaita           #+#    #+#             */
/*   Updated: 2025/02/15 10:55:31 by fmaaita          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "fractol.h"

void	error_handler(t_info *data, int ac, char **av)
{
	if (!(!ft_strncmp(av[1], "Mandelbrot", 11) && ac == 2)
		&& !((ac == 2 || ac == 4) && !ft_strncmp(av[1], "Julia", 6)))
	{
		perror("Available options are:\n\t--> Mandelbrot\n\t--> Julia\n");
		exit(0);
	}
	if (!ft_strncmp(av[1], "Mandelbrot", 11))
		data->fractal.id = 1;
	if (!ft_strncmp(av[1], "Julia", 6))
	{
		data->fractal.id = 2;
		if (ac == 2)
		{
			data->fractal.cx = CX;
			data->fractal.cy = CY;
		}
		else
		{
			data->fractal.cx = atod(av[2]);
			data->fractal.cy = atod(av[3]);
		}
	}
}

void	setter(t_info *data, int ac, char **av)
{
	error_handler(data, ac, av);
	data->height = 900;
	data->width = 1600;
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		exit(0);
	data->win_ptr = mlx_new_window(data->mlx_ptr,
			data->width, data->height, "fract-ol");
	data->img.img_ptr = mlx_new_image(data->mlx_ptr,
			data->width, data->height);
	data->fractal.zoom = 250;
	data->fractal.offset_x = 0;
	data->fractal.offset_y = 0;
	data->img.buffer = (int *)mlx_get_data_addr(data->img.img_ptr,
			&data->img.bpp, &data->img.size_line, &data->img.endian);
}

int	render(t_info *data)
{
	pixel_iterator(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img.img_ptr, 0, 0);
	return (0);
}

int	main(int ac, char **av)
{
	t_info	data;

	setter(&data, ac, av);
	mlx_mouse_get_pos(data.mlx_ptr, data.win_ptr, &data.mx, &data.my);
	mlx_mouse_hook(data.win_ptr, &mouse_handler, &data);
	mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_hook(data.win_ptr, DestroyNotify,
		StructureNotifyMask, &ft_close, &data);
	mlx_key_hook(data.win_ptr, &key_handler, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
