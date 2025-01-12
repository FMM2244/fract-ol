/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_controls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaaita <fmaaita@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 13:01:46 by fmaaita           #+#    #+#             */
/*   Updated: 2025/01/12 12:56:59 by fmaaita          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "fractol.h"

/**
 * this function determines the color of the pixel based on the no. iterations
**/
void	color_handler(t_info *data, int i)
{
	if (i == max_no_iterations)
		data->img.buffer[(data->img.size_line / 4) * data->fractal.y + data->fractal.x] = 0x000000;
	else
		data->img.buffer[(data->img.size_line / 4) * data->fractal.y + data->fractal.x] = COLOR * i;
}

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

/**
 * the second function is to iterate through the Mandelbrot function
 * as the name suggests 
 * the Mandelbrot function is 
**/
int	mandelbrot(t_info *data)
{
	int		i;

	data->fractal.zx = 0.0;
	data->fractal.zy = 0.0;
	data->fractal.cx = data->fractal.xmin + (data->fractal.xmax - data->fractal.xmin) * (data->fractal.x / data->width);
	data->fractal.cy = data->fractal.ymin + (data->fractal.ymax - data->fractal.ymin) * (data->fractal.y / data->height);
	i = checker(&data->fractal);
	color_handler(data, i);
	return (0);
}

/**
 * the third function is to iterate through the Julia set 
 * cx = c real 
 * cy = c imageniry 
**/
int	julia(t_info *data, double cx, double cy)
{
	//int	i;

	data->fractal.cx = cx;
	data->fractal.cy = cy;
	//i = checker(fractal);
	//color_handler(fractal, i);
	return (0);
}


/**
 * the first function iterates through all pixels on the window
 * and call the correct 
 * function based on the users input
**/
int	pixel_iterator(t_info *data, double cx, double cy)
{
	data->fractal.y = 0;
	while (data->fractal.y < data->height)
	{
		data->fractal.x = 0;
		while (data->fractal.x < data->width)
		{
			if (data->fractal.id == 1)
				mandelbrot(data);
			if (data->fractal.id == 2)
				julia(data, cx, cy);
			mlx_pixel_put(data->mlx_ptr, data->win_ptr, data->fractal.x, data->fractal.y, COLOR);
			data->fractal.x++;
		}
		data->fractal.y++;
	}
	return (0);
}
