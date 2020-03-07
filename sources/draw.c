/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 21:41:25 by mcarc             #+#    #+#             */
/*   Updated: 2020/01/21 14:48:48 by mcarc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		iso_proj(float *x, float *y, int z)
{
	*x = (*x - *y) * cos(0.89);
	*y = (*x + *y) * sin(0.56) - z;
}

void		draw_zoom(float point[4], t_mlx *mlx)
{
	point[0] *= mlx->zoom;
	point[2] *= mlx->zoom;
	point[1] *= mlx->zoom;
	point[3] *= mlx->zoom;
}

void		draw_shift(float point[4], t_mlx *mlx)
{
	point[0] += mlx->x_shift;
	point[2] += mlx->x_shift;
	point[1] += mlx->y_shift;
	point[3] += mlx->y_shift;
}

void		draw_line(float p[4], t_mlx *mlx)
{
	float	step[2];
	float	max;
	int		az;
	int		bz;

	az = mlx->matrix[(int)p[1]][(int)p[0]] * mlx->scale;
	bz = mlx->matrix[(int)p[3]][(int)p[2]] * mlx->scale;
	draw_zoom(p, mlx);
	if (mlx->iso == 1)
	{
		iso_proj(&p[0], &p[1], az);
		iso_proj(&p[2], &p[3], bz);
	}
	draw_shift(p, mlx);
	step[0] = p[2] - p[0];
	step[1] = p[3] - p[1];
	max = max_float(abs_float(step[0]), abs_float(step[1]));
	step[0] /= max;
	step[1] /= max;
	while ((int)(p[0] - p[2]) || (int)(p[1] - p[3]))
	{
		mlx_pixel_put(mlx->mlx, mlx->win, p[0], p[1], (az + 1) * mlx->color);
		p[0] += step[0];
		p[1] += step[1];
	}
}

void		draw(t_mlx *mlx)
{
	int		x;
	int		y;
	float	px[4];
	float	py[4];

	y = 0;
	ft_menu(mlx);
	while (y < mlx->height)
	{
		x = 0;
		while (x < mlx->width)
		{
			fill_array(px, py, x, y);
			if (x < mlx->width - 1)
				draw_line(px, mlx);
			if (y < mlx->height - 1)
				draw_line(py, mlx);
			x++;
		}
		y++;
	}
}
