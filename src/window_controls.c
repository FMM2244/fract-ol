/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_controls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaaita <fmaaita@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 18:56:40 by fmaaita           #+#    #+#             */
/*   Updated: 2024/12/09 19:52:10 by fmaaita          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "fractol.h"

void	*start_window(void *initializer)
{
	void	*window_ptr;

	initializer = NULL;
	initializer = mlx_init();
	window_ptr = mlx_new_window(initializer, 1200, 1000, "fract-ol");
	return (window_ptr);
}

void	window_display_end(void *initializer, void *window_ptr)
{
	mlx_clear_window(initializer, window_ptr);
	mlx_destroy_window(initializer, window_ptr);
	mlx_destroy_display(initializer);
}

