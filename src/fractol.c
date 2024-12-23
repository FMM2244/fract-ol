/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaaita <fmaaita@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 18:44:53 by fmaaita           #+#    #+#             */
/*   Updated: 2024/12/16 16:54:31 by fmaaita          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "fractol.h"

int	main(int ac, char **av)
{
	void	*window_ptr;
	void	*init;

	if (ac == 2 && (!ft_strncmp(av[1], "Mandelbrot", 11) 
			|| !ft_strncmp(av[1], "Julia", 6)))
    {
		init = mlx_init();
		window_ptr = mlx_new_window(init, 1024, 728, "fract-ol");
		mlx_loop_hook(init, &no_event_handler, &window_ptr);
		mlx_key_hook(window_ptr, &esc_handler, &init);
		mlx_loop(init);
    }
	else
	{
		write(1, "Sorry! an error occured. ", 25);
		write(1, "Available options are:\n\t--> Mandelbrot\n\t--> Julia\n", 50);
	}
	return (0);
}
