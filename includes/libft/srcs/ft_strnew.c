/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 12:30:18 by mcarc             #+#    #+#             */
/*   Updated: 2019/09/25 14:42:22 by mcarc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnew(size_t size)
{
	char *start;

	start = (char *)malloc(sizeof(*start) * (size + 1));
	if (!start)
		return (NULL);
	ft_bzero(start, size + 1);
	return (start);
}
