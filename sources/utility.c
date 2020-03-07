/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 15:12:19 by mcarc             #+#    #+#             */
/*   Updated: 2020/01/21 15:12:20 by mcarc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int				count_n(char *arg, int count)
{
	int			fd;
	int			n;
	char		buf;

	n = 0;
	fd = open(arg, O_RDONLY);
	while (read(fd, &buf, 1))
	{
		if (buf == '\n')
			n++;
	}
	close(fd);
	if (n != count)
		return (0);
	return (1);
}

void			fill_array(float px[4], float py[4], int x, int y)
{
	px[0] = x;
	px[1] = y;
	px[2] = x + 1;
	px[3] = y;
	py[0] = x;
	py[1] = y;
	py[2] = x;
	py[3] = y + 1;
}

int				word_count(const char *str, char c)
{
	int	k;

	k = 0;
	while (*str)
	{
		while (*str == c)
			str++;
		if (*str != '\0')
			k++;
		while (*str != c && *str != '\0')
			str++;
	}
	return (k);
}

float			abs_float(float a)
{
	if (a > 0)
		return (a);
	return (-a);
}

float			max_float(float a, float b)
{
	if (a > b)
		return (a);
	return (b);
}
