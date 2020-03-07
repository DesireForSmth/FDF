/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 14:44:17 by mcarc             #+#    #+#             */
/*   Updated: 2020/02/15 15:06:46 by mcarc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		ft_menu(t_mlx *data)
{
	mlx_string_put(data->mlx, data->win, 10, 10, 0xAAAAAA,
			"Push '-' and '+' to scale points");
	mlx_string_put(data->mlx, data->win, 10, 40, 0xAAAAAA,
			"Push 'W' and 'S' to zoom your image");
	mlx_string_put(data->mlx, data->win, 10, 70, 0xAAAAAA,
			"Push arrow keys to move");
	mlx_string_put(data->mlx, data->win, 10, 100, 0xAAAAAA,
			"Push 'I' to change  projection");
	mlx_string_put(data->mlx, data->win, 10, 130, 0xAAAAAA,
			"Push keys between 'Z' and 'N' to change colour");
	mlx_string_put(data->mlx, data->win, 10, 160, 0xAAAAAA,
			"Push space to reset settings");
}

int			ft_check_map(t_mlx *mlx)
{
	int	i;

	i = 0;
	while ((mlx->gnl = get_next_line(mlx->fd, &mlx->str)) != 0)
	{
		if (mlx->str[i] == '\0' || mlx->str[0] == '/')
			return (0);
		mlx->count1 += mlx->gnl;
		while (mlx->str[i] != '\0')
		{
			if ((mlx->str[i] == ' ' || mlx->str[i] == '\t') && (i == 0))
				return (0);
			if (mlx->str[i] >= '0' && mlx->str[i] <= '9')
				mlx->count++;
			i++;
		}
		if ((mlx->str[i] == '\0' && !mlx->str[i - 1]) || !(mlx->count))
			return (0);
		i = 0;
		free(mlx->str);
	}
	if (!(count_n(mlx->arg, mlx->count1)))
		return (0);
	return (1);
}

int			init(t_mlx *mlx)
{
	mlx->zoom = 20;
	mlx->x_shift = 400;
	mlx->y_shift = 300;
	mlx->scale = 1;
	mlx->iso = 1;
	mlx->color = CZ;
	mlx->count = 0;
	if (!(mlx->mlx = mlx_init()))
		return (0);
	if (!(mlx->win = mlx_new_window(mlx->mlx, 1200, 900, "FDF")))
	{
		free(mlx->mlx);
		return (0);
	}
	return (1);
}

void		arg_check(int argc, char **argv)
{
	int		fd;
	char	*str;

	str = 0;
	if (argc != 2)
		error_exit(1, NULL);
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		error_exit(1, NULL);
	get_next_line(fd, &str);
	if (!str)
		error_exit(2, NULL);
	free(str);
	close(fd);
}

int			main(int argc, char **argv)
{
	t_mlx *mlx;

	arg_check(argc, argv);
	if (!(mlx = (t_mlx *)malloc(sizeof(t_mlx))))
		error_exit(3, NULL);
	else
	{
		mlx->count = 0;
		mlx->count1 = 0;
		mlx->gnl = 0;
		mlx->str = 0;
		mlx->fd = open(argv[1], O_RDONLY);
		mlx->arg = argv[1];
	}
	if (!(ft_check_map(mlx)) || !(mlx->count))
	{
		close(mlx->fd);
		error_exit(2, NULL);
	}
	read_matrix(mlx, argv[1]);
	init(mlx);
	draw(mlx);
	mlx_key_hook(mlx->win, key_deal, mlx);
	mlx_loop(mlx->mlx);
	return (0);
}
