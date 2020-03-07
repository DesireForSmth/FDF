/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_deal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 13:58:42 by mcarc             #+#    #+#             */
/*   Updated: 2020/02/15 15:07:03 by mcarc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	reset(t_mlx *mlx)
{
	mlx->zoom = 20;
	mlx->x_shift = 400;
	mlx->y_shift = 300;
	mlx->scale = 1;
	mlx->iso = 1;
	mlx->color = CZ;
}

void	redraw_more(int keycode, t_mlx *mlx)
{
	if (keycode == 24)
		mlx->scale += 1;
	else if (keycode == 34)
		mlx->iso *= -1;
	else if (keycode == 6)
		mlx->color = CZ;
	else if (keycode == 7)
		mlx->color = CX;
	else if (keycode == 8)
		mlx->color = CC;
	else if (keycode == 9)
		mlx->color = CV;
	else if (keycode == 11)
		mlx->color = CB;
	else if (keycode == 45)
		mlx->color = CN;
	else if (keycode == 49)
		reset(mlx);
	mlx_clear_window(mlx->mlx, mlx->win);
	draw(mlx);
}

void	redraw(int keycode, t_mlx *mlx)
{
	if (keycode == 126)
		mlx->y_shift -= 10;
	else if (keycode == 125)
		mlx->y_shift += 10;
	else if (keycode == 124)
		mlx->x_shift += 10;
	else if (keycode == 123)
		mlx->x_shift -= 10;
	else if (keycode == 13)
		mlx->zoom += 5;
	else if (keycode == 1)
		mlx->zoom -= 5;
	else if (keycode == 27)
		mlx->scale -= 1;
	return (redraw_more(keycode, mlx));
}

int		key_deal(int keycode, t_mlx *mlx)
{
	if (keycode == 53)
		exit(0);
	else
		redraw(keycode, mlx);
	return (0);
}
