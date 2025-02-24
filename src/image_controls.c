/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_controls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaaita <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 22:57:49 by fmaaita           #+#    #+#             */
/*   Updated: 2025/01/15 22:58:06 by fmaaita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/**
 * this function determines the color of the pixel based on the no. iterations
**/
void	color_handler(t_info *data, int i)
{
	if (i == MAX_NO_ITERATIONS)
		data->img.buffer[(data->img.size_line / 4)
			* data->fractal.y + data->fractal.x] = 0x000000;
	else
		data->img.buffer[(data->img.size_line / 4)
			* data->fractal.y + data->fractal.x] = COLOR1 * i;
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
	while (i < MAX_NO_ITERATIONS)
	{
		temp = fractal->zx;
		fractal->zx = fractal->zx * fractal->zx - fractal->zy * fractal->zy
			+ fractal->cx;
		fractal->zy = 2 * fractal->zy * temp + fractal->cy;
		if (fractal->zx * fractal->zx > DBL_MAX)
			break ;
		if (fractal->zx == x_init && fractal->zy == y_init)
		{
			i = MAX_NO_ITERATIONS;
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
	data->fractal.cx = (data->fractal.x - data->width / 2)
		/ data->fractal.zoom + data->fractal.offset_x;
	data->fractal.cy = (data->fractal.y - data->height / 2)
		/ data->fractal.zoom + data->fractal.offset_y;
	i = checker(&data->fractal);
	color_handler(data, i);
	return (0);
}

/**
 * the third function is to iterate through the Julia set 
 * cx = c real 
 * cy = c imageniry 
**/
int	julia(t_info *data)
{
	int	i;

	data->fractal.zx = (data->fractal.x - data->width / 2)
		/ data->fractal.zoom + data->fractal.offset_x;
	data->fractal.zy = (data->fractal.y - data->height / 2)
		/ data->fractal.zoom + data->fractal.offset_y;
	i = checker(&data->fractal);
	color_handler(data, i);
	return (0);
}

/**
 * the first function iterates through all pixels on the window
 * and call the correct 
 * function based on the users input
**/
int	pixel_iterator(t_info *data)
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
				julia(data);
			data->fractal.x++;
		}
		data->fractal.y++;
	}
	return (0);
}
