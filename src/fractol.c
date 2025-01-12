/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaaita <fmaaita@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 18:44:53 by fmaaita           #+#    #+#             */
/*   Updated: 2025/01/12 14:17:45 by fmaaita          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "fractol.h"

void	error_handler(int ac, char *name)
{
	if ((ft_strncmp(name, "Mandelbrot", 11) || ac != 2)
		&& ((ac == 2 || ac == 4)
			&& ft_strncmp(name, "Julia", 6)))
	{
		perror("Available options are:\n\t--> Mandelbrot\n\t--> Julia\n");
		exit(0);
	}
}

void	setter(t_info *data, int ac, char *name)
{
	error_handler(ac, name);
	if (!ft_strncmp(name, "Mandelbrot", 11))
		data->fractal.id = 1;
	if (!ft_strncmp(name, "Julia", 6))
		data->fractal.id = 2;
	data->height = 728;
	data->width = 1024;
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		exit(0);
	data->win_ptr = mlx_new_window(data->mlx_ptr,
		data->width, data->height, "fract-ol");
	data->img.img_ptr = mlx_new_image(data->mlx_ptr,
		data->width, data->height);
	data->fractal.xmin = -7;
	data->fractal.xmax = 7;
	data->fractal.ymin = -3;
	data->fractal.ymax = 3;
	data->img.buffer = (int *)mlx_get_data_addr(data->img.img_ptr, &data->img.bpp, &data->img.size_line ,&data->img.endian);
}

int	render(t_info *data)
{
	pixel_iterator(data, 0, 0);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img_ptr, 0, 0);
	return (0);
}

int	main(int ac, char **av)
{
	t_info		data;

	setter(&data, ac, av[1]);
	mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_hook(data.win_ptr, DestroyNotify,
		StructureNotifyMask, &ft_close, &data);
	mlx_key_hook(data.win_ptr, &key_handler, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
