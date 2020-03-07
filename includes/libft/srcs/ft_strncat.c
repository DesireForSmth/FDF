/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 17:03:59 by mcarc             #+#    #+#             */
/*   Updated: 2019/09/23 19:45:39 by mcarc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static size_t	ft_min(size_t a, size_t b)
{
	if (a <= b)
		return (a);
	return (b);
}

char			*ft_strncat(char *s1, const char *s2, size_t n)
{
	char		*str;
	size_t		size;

	str = s1;
	size = ft_min(n, ft_strlen(s2));
	str += ft_strlen(s1);
	ft_memcpy(str, s2, size);
	str += size;
	*str = '\0';
	return (s1);
}
