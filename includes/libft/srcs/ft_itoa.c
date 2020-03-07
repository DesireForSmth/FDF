/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:04:56 by mcarc             #+#    #+#             */
/*   Updated: 2019/09/23 19:45:39 by mcarc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static	void	ft_filling(char *str, int n, size_t size, long int base)
{
	char		*tmp;
	long int	tmp_int;

	tmp = str;
	tmp_int = (long int)n;
	if (n < 0)
		tmp_int *= -1;
	if (n < 0)
	{
		*tmp = '-';
		size--;
		tmp++;
	}
	while (size)
	{
		*tmp = tmp_int / base + '0';
		tmp_int %= base;
		base /= 10;
		size--;
		tmp++;
	}
	*tmp = '\0';
}

char			*ft_itoa(int n)
{
	long int	base;
	size_t		size;
	char		*str;

	size = 0;
	base = 1;
	if (n < 0)
		size++;
	while (n / base)
	{
		base *= 10;
		size++;
	}
	if (n == 0)
		size = 1;
	else
		base /= 10;
	str = ft_strnew(size);
	if (!str)
		return (NULL);
	ft_filling(str, n, size, base);
	return (str);
}
