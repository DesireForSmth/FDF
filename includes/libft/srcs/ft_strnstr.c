/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 15:44:54 by mcarc             #+#    #+#             */
/*   Updated: 2019/09/23 19:45:39 by mcarc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*dst;
	char	*dst_tmp;
	char	*src;
	char	*haystack_size;
	size_t	needle_size;

	haystack_size = (char *)haystack + len;
	needle_size = ft_strlen(needle);
	dst = (char *)haystack;
	src = (char *)needle;
	if (*src == '\0')
		return (dst);
	while (*dst != '\0' && dst + needle_size <= haystack_size)
	{
		dst_tmp = dst++;
		if (*dst_tmp == *src && ft_memcmp(dst_tmp, src, needle_size) == 0)
			return (dst_tmp);
	}
	return (NULL);
}
