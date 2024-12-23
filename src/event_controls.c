/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_controls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaaita <fmaaita@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 18:33:31 by fmaaita           #+#    #+#             */
/*   Updated: 2024/12/16 14:59:14 by fmaaita          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "fractol.h"

int	no_event_handler(void *win_ptr, void *init)
{
	(void)win_ptr;
	(void)init;
	return (0);
}

int	esc_handler(int key, void *win_ptr, void *init)
{
	if (key == XK_Escape)
		window_display_end(init, win_ptr);
	(void)win_ptr;
	(void)init;
	return (0);
}
