/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_controls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaaita <fmaaita@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 13:01:46 by fmaaita           #+#    #+#             */
/*   Updated: 2025/01/06 21:06:51 by fmaaita          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "fractol.h"

/**
 * the first function iterates through all pixels on the window
 * and call the correct 
 * function based on the users input
**/
int	pixel_iterator(t_info *data,
	t_fractal *fractal, double cx, double cy)
{
	fractal->x = 0;
	fractal->y = 0;
	while (fractal->x < data->width)
	{
		while (fractal->y < data->height)
		{
			if (fractal->id == 1)
				mandelbrot(fractal);
			if (fractal->id == 2)
				julia(fractal, cx, cy);
			fractal->y++;
		}
		fractal->x++;
		fractal->y = 0;
	}
	put_pixel_to_image(data->mlx_ptr, data->win_ptr, data->img.img_ptr, 0, 0);
	return (0);
}

/**
 * the second function is to iterate through the Mandelbrot function
 * as the name suggests 
 * the Mandelbrot function is 
**/
int	mandelbrot(t_fractal *fractal)
{
	//int		i;

	fractal->zx = 0.0;
	fractal->zy = 0.0;
	fractal->cx = fractal->x / fractal->zoom + fractal->offset_x;
	fractal->cy = fractal->y / fractal->zoom + fractal->offset_y;
	//i = checker(fractal);
	//color_handler(fractal, i);
	return (0);
}

/**
 * the third function is to iterate through the Julia set 
 * cx = c real 
 * cy = c imageniry 
**/
int	julia(t_fractal *fractal, double cx, double cy)
{
	//int	i;

	fractal->cx = cx;
	fractal->cy = cy;
	fractal->cx = fractal->x / fractal->zoom + fractal->offset_x;
	fractal->cy = fractal->y / fractal->zoom + fractal->offset_y;
	//i = checker(fractal);
	//color_handler(fractal, i);
	return (0);
}
/**
 * this function determines the color of the pixel based on the no. iterations
**/
void	color_handler(t_fractal *fractal, int i)
{
	if (i == max_no_iterations)
		color_pixel(fractal->x, fractal->y, 0x000000);
	else
		color_pixel(fractal->x, fractal->y, COLOR * i);
}

/**
 * 
**/


/**
 * this functions responsibility is to iterate
 * through the orbit and check if the
 * point is part of the set or not
 * 
 * it returns the number of iterations
 * 
 * if the point is part of the set it sets i to the no.
 * max iterations to be colored black
 * otherwise it returns the i as its self 
**/
int	checker(t_fractal *fractal)
{
	int		i;
	double	temp;
	double	x_init;
	double	y_init;

	x_init = fractal->zx;
	y_init = fractal->zy;
	i = 0;
	while (i < max_no_iterations)
	{
		temp = fractal->zx;
		fractal->zx = fractal->zx * fractal->zx - fractal->zy * fractal->zy
			+ fractal->cx;
		fractal->zy = 2 * fractal->zy * temp + fractal->cy;
		if (fractal->zx * fractal->zx > DBL_MAX)
			break ;
		if (fractal->zx == x_init && fractal->zy == y_init)
		{
			i = max_no_iterations;
			break ;
		}
		i++;
	}
	return (i);
}

