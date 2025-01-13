/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_controls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaaita <fmaaita@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 18:33:31 by fmaaita           #+#    #+#             */
/*   Updated: 2025/01/12 22:02:32 by fmaaita          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "fractol.h"

int	ft_close(t_info *data)
{
	mlx_destroy_image(data->mlx_ptr, data->win_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_loop_end(data->mlx_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
	return (0);
}

int	key_handler(int key, t_info *data)
{
	if (key == XK_Escape)
		ft_close(data);
	else if (key == )
	{
		
	}
	else if (key == )
	{
		
	}
	return (0);
}

void	atod_errors(char *num)
{
	int = 0;

	if ((num[0] != '+' && num[0] != '-' && num[0] > 47 && num[0] < 57) && (ft_strchr(num, '.') - ft_strrchr(num, '.')))
	{
		perror("Invalid numbers, try again");
		exit(0);
	}
	i = 0;
	while (!num[++i])
	{
		if ((num[i] > 47 && num[i] < 57) || num[i] != '.')
		{
			perror("Invalid numbers, try again");
			exit(0);
		}
	}
}

double	atod(char *num)
{
	double	double_value;
	int		int_value;
	int		i;
	int             sign;

	i = -1;
	sign = 1;
	if (num[0] == '-')
                sign = -1;
	while (num[++i] != '.')
		int_value = int_value * 10 + num[i] - '0';

}
