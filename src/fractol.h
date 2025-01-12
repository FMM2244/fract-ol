/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaaita <fmaaita@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 12:32:50 by fmaaita           #+#    #+#             */
/*   Updated: 2025/01/12 13:48:28 by fmaaita          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef FRACTOL_H
# define FRACTOL_H
# define max_no_iterations 750
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

typedef struct s_fractal
{
	int		id;
	int		x;
	int		y;
	int		xmin;
	int		ymin;
	int		xmax;
	int		ymax;
	double	zx;
	double	zy;
	double	cx;
	double	cy;
	double	zoom;
}			t_fractal;

typedef struct s_img
{
	void	*img_ptr;
	int		*buffer;
	int		bpp;
	int		size_line;
	int		endian;
} 			t_img;


typedef struct s_info
{
	t_fractal	fractal;
	t_img		img;
	void		*mlx_ptr;
	void		*win_ptr;
	int			height;
	int 		width;
}				t_info;


int	ft_close(t_info *data);
int	key_handler(int key, t_info *data);
int	pixel_iterator(t_info *data, double cx, double cy);
int	mandelbrot(t_info *data);
int	julia(t_info *data, double cx, double cy);

#endif
