/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_gen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaaita <fmaaita@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 18:56:40 by fmaaita           #+#    #+#             */
/*   Updated: 2024/12/04 19:24:04 by fmaaita          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "fractol.h"

void	*start_window()
{
	t_xvar	*initializer;
	t_win_list	*window_ptr;

	initializer = mlx_init();
	window_ptr = mlx_new_window(initializer, 1200, 1000, "fract-ol");
	return (window_ptr);
}