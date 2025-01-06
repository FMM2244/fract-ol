/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaaita <fmaaita@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 12:32:50 by fmaaita           #+#    #+#             */
/*   Updated: 2025/01/06 20:25:58 by fmaaita          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef FRACTOL_H
# define FRACTOL_H
# define max_no_iterations 200
# define COLOR 0xFCBE11

# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include <stdarg.h>
# include <stdio.h>
# include <float.h>
# include "libft/libft.h"

typedef struct s_img
{
	void	*img_ptr;
	int		*buffer;
	int		bpp;
	int		size_line;
	int		endian;
} t_img;


typedef struct s_info
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	int		height;
	int 	width;
}	t_info;

typedef struct s_fractal
{
	int		id;
	int		x;
	int		y;
	double	zx;
	double	zy;
	double	cx;
	double	cy;
	double	offset_x;
	double	offset_y;
	double	zoom;
}	t_fractal;

int	ft_close(t_info *data);
int	key_handler(int key, t_info *data);
int	pixel_iterator(t_info *data, t_fractal *fractal, double cx, double cy);
int	mandelbrot(t_fractal *fractal);
int	julia(t_fractal *fractal, double cx, double cy);

#endif
