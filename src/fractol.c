/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaaita <fmaaita@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 18:44:53 by fmaaita           #+#    #+#             */
/*   Updated: 2024/12/08 21:34:04 by fmaaita          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "fractol.h"

int	main(int ac, char **av)
{
	void	*window_ptr;
	window_ptr = NULL;
	if (ac == 2 && (!ft_strcmp(av[1], "Mandelbrot") || !ft_strcmp(av[1], "Julia")))
    {
		window_ptr = start_window();
		i = -1000;
		while (i <= 1000000000)
		{
			i++;
		}
		window_display_end(window_ptr);
    }
	else
		write(1, "Sorry! an error occured. Available options are:\n\t--> Mandelbrot\n\t--> Julia\n", 74);
	return (0);
}
