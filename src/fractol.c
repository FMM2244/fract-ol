/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaaita <fmaaita@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 18:44:53 by fmaaita           #+#    #+#             */
/*   Updated: 2024/12/30 19:23:11 by fmaaita          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "fractol.h"

int	main(int ac, char **av)
{
	w_info	data;

	data.height = 1024;
	data.width = 728;
	if (ac == 2 && (!ft_strncmp(av[1], "Mandelbrot", 11) 
			|| !ft_strncmp(av[1], "Julia", 6)))
    {
		data.mlx_ptr = mlx_init();
		if (!data.mlx_ptr)
			return (0);
		data.win_ptr = mlx_new_window(data.mlx_ptr, data.height, data.width, "fract-ol");
		mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &ft_close, &data);
		mlx_key_hook(data.win_ptr, &key_handler, &data);
		mlx_loop(data.mlx_ptr);
    }
	else
	{
		write(1, "Sorry! an error occured. ", 25);
		write(1, "Available options are:\n\t--> Mandelbrot\n\t--> Julia\n", 50);
	}
	return (0);
}
