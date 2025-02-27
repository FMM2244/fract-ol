/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaaita <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 22:56:08 by fmaaita           #+#    #+#             */
/*   Updated: 2025/01/15 22:56:12 by fmaaita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define MAX_NO_ITERATIONS 200
# define COLOR1 0xB08FF3
# define COLOR2 0xFF
# define COLOR3 0x2410FF
# define CX 0.285
# define CY 0.01

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
	int		offset_x;
	int		offset_y;
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
}			t_img;

typedef struct s_info
{
	t_fractal	fractal;
	t_img		img;
	void		*mlx_ptr;
	void		*win_ptr;
	int			height;
	int			width;
	int			mx;
	int			my;
}				t_info;

double	atod(char *num);
int		ft_close(t_info *data);
int		key_handler(int key, t_info *data);
int		pixel_iterator(t_info *data);
int		mandelbrot(t_info *data);
int		julia(t_info *data);
int		mouse_handler(int code, int x, int y, t_info *data);

#endif
