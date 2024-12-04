/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 19:19:54 by fmaaita           #+#    #+#             */
/*   Updated: 2024/12/02 00:51:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>

int	main(int ac, char **av)
{
	if (ac == 2 && (!ft_strcmp(av[1], "Mandelbrot") || !ft_strcmp(av[1], "Julia")))
	{
		
	}
	else
		write(1, "Sorry! an error occured. Available options are:\n\t--> Mandelbrot\n\t--> Julia\n", 74);
	return (0);
}
