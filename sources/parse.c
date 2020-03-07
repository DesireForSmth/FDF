/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 17:52:22 by mcarc             #+#    #+#             */
/*   Updated: 2020/01/21 15:02:53 by mcarc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			get_height(char *arg)
{
	char	*line;
	int		fd;
	int		height;

	height = 0;
	fd = open(arg, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		free(line);
		height++;
	}
	close(fd);
	return (height);
}

int			get_width(char *arg)
{
	char	*line;
	int		fd;
	int		width;

	fd = open(arg, O_RDONLY, 0);
	get_next_line(fd, &line);
	width = word_count(line, ' ');
	free(line);
	close(fd);
	return (width);
}

void		free_matrix(t_mlx *mlx)
{
	int		i;

	i = 0;
	while (mlx->matrix[i])
	{
		free(mlx->matrix[i]);
		i++;
	}
	free(mlx->matrix);
}

int			fill_matrix(int *matrix, char *line, t_mlx *mlx)
{
	char	**nums;
	int		i;

	i = 0;
	if (word_count(line, ' ') != mlx->width)
		return (0);
	nums = ft_strsplit(line, ' ');
	while (nums[i])
	{
		matrix[i] = ft_atoi(nums[i]);
		free(nums[i]);
		i++;
	}
	free(nums);
	return (1);
}

void		read_matrix(t_mlx *mlx, char *arg)
{
	int		fd;
	int		i;
	char	*line;

	mlx->height = get_height(arg);
	mlx->width = get_width(arg);
	mlx->matrix = (int **)ft_memalloc(sizeof(int *) * (mlx->height + 1));
	i = 0;
	while (i < mlx->height)
		mlx->matrix[i++] = (int *)ft_memalloc(sizeof(int) * (mlx->width + 1));
	i = 0;
	fd = open(arg, O_RDONLY, 0);
	while (i < mlx->height)
	{
		get_next_line(fd, &line);
		if ((fill_matrix(mlx->matrix[i], line, mlx)) == 0)
		{
			free(line);
			error_exit(2, mlx);
		}
		free(line);
		i++;
	}
	close(fd);
	mlx->matrix[i] = NULL;
}
