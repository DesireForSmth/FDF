/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 13:58:01 by mcarc             #+#    #+#             */
/*   Updated: 2020/01/21 14:06:25 by mcarc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	error_exit(int error, t_mlx *mlx)
{
	if (error == 1)
	{
		ft_putstr("usage: ./fdf source_file\n");
		exit(EXIT_FAILURE);
	}
	if (error == 2)
	{
		ft_putstr("invalid map\n");
		exit(EXIT_FAILURE);
	}
	if (error == 3)
	{
		ft_putstr("mlx allocation failed\n");
		exit(EXIT_FAILURE);
	}
	if (!mlx)
	{
		ft_putstr("You are faggot\n");
		exit(0);
	}
	if (error == 4)
	{
		ft_putstr("You tried open a directory");
		exit(EXIT_FAILURE);
	}
}
