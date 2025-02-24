/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaaita <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 22:55:13 by fmaaita           #+#    #+#             */
/*   Updated: 2025/01/15 22:55:18 by fmaaita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	atod_errors(char *num)
{
	long	test1;
	int		i;

	test1 = ft_strchr(num, '.') - ft_strrchr(num, '.');
	if (num[0] == '+' || num[0] == '-')
		num++;
	if (test1)
	{
		if (errno)
			perror("Invalid numbers, try again");
		exit(1);
	}
	i = 0;
	if (!ft_isdigit(num[i]))
		exit(1);
	while (!num[i])
	{
		if (ft_isdigit(num[i]) && num[i] != '.')
		{
			perror("Invalid numbers, try again");
			exit(1);
		}
		i++;
	}
}

void	init_setter(int *int_value, int *ten, int *sign, double *double_value)
{
	*int_value = 0;
	*double_value = 0;
	*sign = 1;
	*ten = 1;
}

double	atod(char *num)
{
	double		double_value;
	int			int_value;
	int			i;
	int			ten;
	int			sign;

	atod_errors(num);
	init_setter(&int_value, &ten, &sign, &double_value);
	i = 0;
	if (num[0] == '-' || num[0] == '+')
		if (num[0] == '-' && ++i)
			sign = -1;
	while (num[i] != '.' && num[i] != 0)
	{
		int_value += (num[i++] - '0');
		int_value *= 10;
	}
	if (num[i] == '.')
		i++;
	while (num[i] != 0)
	{
		double_value += (double)(num[i++] - '0') / ten;
		ten *= 10;
	}
	return (((int_value / 10) + (double_value / 10)) * sign);
}
