/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_controls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaaita <fmaaita@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 18:56:40 by fmaaita           #+#    #+#             */
/*   Updated: 2024/12/08 21:24:13 by fmaaita          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "fractol.h"

void	*start_window()
{
	t_xvar	*initializer;
	t_win_list	*window_ptr;

	window_ptr = NULL;
	initializer = NULL;
	initializer = mlx_init();
	window_ptr = mlx_new_window(initializer, 1200, 1000, "fract-ol");
	return (window_ptr);
}

void	window_display_end()
{
	
}

