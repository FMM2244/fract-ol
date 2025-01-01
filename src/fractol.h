/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaaita <fmaaita@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 12:32:50 by fmaaita           #+#    #+#             */
/*   Updated: 2025/01/01 20:00:01 by fmaaita          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef FRACTOL_H
# define FRACTOL_H

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

typedef struct t_info
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	int		height;
	int 	width;
}	w_info;

typedef struct t_fractal
{
	int		x;
	int		y;
	double	zx;
	double	zy;
	double	cx;
	double	cy;
	double	offset_x;
	double	offset_y;
	double	zoom;
}	fractal;

int	ft_close(w_info *data);
int	key_handler(int key, w_info *data);
int	pixel_iterator(char *name, w_info *data, fractal *fractal);

#endif
