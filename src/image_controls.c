/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_controls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaaita <fmaaita@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 13:01:46 by fmaaita           #+#    #+#             */
/*   Updated: 2025/01/01 19:59:52 by fmaaita          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "fractol.h"

/**
 * the first function iterates through all pixels on the window and call the correct 
 * function based on the users input
**/

int	pixel_iterator(char *name, w_info *data, fractal *fractal)
{
	fractal->x = 0;
	fractal->y = 0;
	while (fractal->x < data->width)
	{
		while (fractal->y < data->height)
		{
			if (!ft_strncmp(name, "Mandelbrot", 10))
				//mandelbrot(fractal);
			if (!ft_strncmp(name, "Julia", 6))
				//julia(fractal);
			fractal->y++;
		}
		fractal->x++;
		fractal->y = 0;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
	return (0);
}

/**
 * the second function is to iterate through the Mandelbrot function as the name suggests 
 * the Mandelbrot function is 
**/
/*
int	mandelbrot(fractal *fractal)
{
	
	return (0);
}*/

/**
 * the third function is to iterate through the Julia set 
 * 
**/