/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 14:44:42 by mcarc             #+#    #+#             */
/*   Updated: 2020/01/21 15:09:51 by mcarc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../minilibx/mlx.h"
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "libft/includes/libft.h"
# define CZ 0xFFFFFF
# define CX 0x0E50BA
# define CC 0xC60707
# define CV 0x8c0fc6
# define CB 0xe8930b
# define CN 0x04963e

typedef struct	s_mlx
{
	void	*mlx;
	void	*win;
	int		height;
	int		width;
	int		**matrix;
	int		zoom;
	int		scale;
	int		color;
	int		x_shift;
	int		y_shift;
	int		iso;
	int		count;
	int		count1;
	char	*arg;
	int		gnl;
	int		fd;
	char	*str;
}				t_mlx;

float			abs_float(float a);
float			max_float(float a, float b);
int				word_count(const char *str, char c);
int				get_height(char *arg);
int				get_width(char *arg);
void			free_matrix(t_mlx *mlx);
int				fill_matrix(int *matrix, char *line, t_mlx *mlx);
void			read_matrix(t_mlx *mlx, char *arg);
void			iso_proj(float *x, float *y, int z);
void			draw_zoom(float point[4], t_mlx *mlx);
void			draw_shift(float point[4], t_mlx *mlx);
void			draw_line(float point[4], t_mlx *mlx);
void			draw(t_mlx *mlx);
void			error_exit(int error, t_mlx *mlx);
int				init(t_mlx *mlx);
void			redraw_more(int keycode, t_mlx *mlx);
void			redraw(int keycode, t_mlx *mlx);
int				key_deal(int keycode, t_mlx *mlx);
void			map_print(t_mlx *mlx);
void			arg_check(int argc, char **argv);
int				main(int argc, char **argv);
void			fill_array(float px[4], float py[4], int x, int y);
void			ft_menu(t_mlx *data);
void			reset(t_mlx *mlx);
int				count_n(char *arg, int count);

#endif
