/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaaita <fmaaita@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 12:32:50 by fmaaita           #+#    #+#             */
/*   Updated: 2024/12/09 13:07:11 by fmaaita          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef FRACTOL_H
# define FRACTOL_H

// # include <stddef.h>
# include <unistd.h>
// # include <stdlib.h>
# include <mlx.h>
# include <math.h>
# include "libft.h"

typedef struct z_point
{
	double	x;
	double	y;
}	i_point;

void	*start_window();
void	window_display_end();

#endif
