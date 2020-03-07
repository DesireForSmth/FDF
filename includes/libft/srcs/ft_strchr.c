/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 18:42:02 by mcarc             #+#    #+#             */
/*   Updated: 2019/09/23 19:45:39 by mcarc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*ft_strchr(const char *s, int c)
{
	char	*tmp;
	size_t	i;

	i = 0;
	tmp = (char *)s;
	while (tmp[i] || (tmp[i] == '\0' && c == '\0'))
	{
		if (tmp[i] == (char)c)
			return (&tmp[i]);
		i++;
	}
	return (NULL);
}
