/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaaita <fmaaita@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 18:44:53 by fmaaita           #+#    #+#             */
/*   Updated: 2025/01/06 20:36:02 by fmaaita          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "fractol.h"

int	main(int ac, char **av)
{
	t_info		data;
	t_fractal	*frctl;

	data.height = 1024;
	data.width = 728;
	if ((!ft_strncmp(av[1], "Mandelbrot", 11) && ac == 2)
		|| ((ac == 2 || ac == 4)
			&& !ft_strncmp(av[1], "Julia", 6)))
	{
		data.mlx_ptr = mlx_init();
		if (!data.mlx_ptr)
			return (0);
		data.win_ptr = mlx_new_window(data.mlx_ptr,
				data.height, data.width, "fract-ol");
		data.img.img_ptr = mlx_new_image(data.mlx_ptr,
				data.width, data.height);
		data.img.buffer = mlx_get_data_addr(data.img.img_ptr, &data.img.bpp, &data.img.endian);
		mlx_hook(data.win_ptr, DestroyNotify,
			StructureNotifyMask, &ft_close, &data);
		mlx_key_hook(data.win_ptr, &key_handler, &data);
		mlx_loop(data.mlx_ptr);
	}
	else
		perror("Available options are:\n\t--> Mandelbrot\n\t--> Julia\n");
	return (0);
}
