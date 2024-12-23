/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaaita <fmaaita@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 12:32:50 by fmaaita           #+#    #+#             */
/*   Updated: 2024/12/16 16:46:53 by fmaaita          ###   ########.fr       */
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
# include "libft.h"

typedef struct z_point
{
	double	x;
	double	y;
}	i_point;

void	*start_window();
void	window_display_end();
int	no_event_handler(void *win_ptr, void *init);
int	esc_handler(int key, void *win_ptr, void *init);

#endif
