/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaaita <fmaaita@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 18:44:53 by fmaaita           #+#    #+#             */
/*   Updated: 2024/12/09 20:23:51 by fmaaita          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "fractol.h"
#include <stdio.h>
int	main(int ac, char **av)
{
	void	*window_ptr;
	void	*init;

	if (ac == 2 && (!ft_strncmp(av[1], "Mandelbrot", 11) || !ft_strncmp(av[1], "Julia", 6)))
    {
		init = mlx_init();
		window_ptr = mlx_new_window(init, 1200, 1000, "fract-ol");
		window_display_end(init, window_ptr);
		free(window_ptr);
		free(init);
    }
	else
		write(1, "Sorry! an error occured. Available options are:\n\t--> Mandelbrot\n\t--> Julia\n", 74);
	return (0);
}
