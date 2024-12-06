/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaaita <fmaaita@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 18:44:53 by fmaaita           #+#    #+#             */
/*   Updated: 2024/12/04 19:15:19 by fmaaita          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "fractol.h"

int	main(int ac, char **av)
{
	
	if (ac == 2 && (!ft_strcmp(av[1], "Mandelbrot") || !ft_strcmp(av[1], "Julia")))
    {
		start_window();	
    }
	else
		write(1, "Sorry! an error occured. Available options are:\n\t--> Mandelbrot\n\t--> Julia\n", 74);
	return (0);
}
