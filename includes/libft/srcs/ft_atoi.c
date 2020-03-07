/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 16:32:07 by mcarc             #+#    #+#             */
/*   Updated: 2019/09/30 11:46:37 by mcarc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static	int			ft_sign(char c)
{
	if (c == '-')
		return (-1);
	return (1);
}

static	int			ft_overflow(unsigned long num, int sign)
{
	if (num > 2147483647 && sign == 1)
		return (-2147483648 + num - 2147483648);
	if (num > 2147483648 && sign == -1)
		return (2147483647 - num + 2147483648);
	else
		return (num);
}

static	int			ft_space(char str)
{
	if (str == ' ' || str == '\n' || str == '\t' ||
		str == '\f' || str == '\v' || str == '\r')
		return (1);
	else
		return (0);
}

int					ft_atoi(const char *str)
{
	long long int	num;
	int				sign;
	long long int	t;

	sign = 1;
	num = 0;
	while (ft_space(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		sign = ft_sign(*str);
		str++;
	}
	while (ft_isdigit(*str))
	{
		t = num * 10 + *str - 48;
		if (t / 10 != num && sign == 1)
			return (-1);
		if (t / 10 != num && sign == -1)
			return (0);
		num = num * 10 + *str - 48;
		str++;
	}
	num = ft_overflow(num, sign);
	return (num * sign);
}
