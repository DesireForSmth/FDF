/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 19:05:51 by mcarc             #+#    #+#             */
/*   Updated: 2019/09/23 19:45:39 by mcarc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*ft_strstr(const char *haystack, const char *needle)
{
	char	*dst;
	char	*dst_tmp;
	char	*src;
	size_t	haystack_size;
	size_t	needle_size;

	haystack_size = ft_strlen(haystack);
	needle_size = ft_strlen(needle);
	dst = (char *)haystack;
	src = (char *)needle;
	if (*src == '\0')
		return (dst);
	while (dst < (haystack + haystack_size))
	{
		dst_tmp = dst++;
		if (ft_memcmp(dst_tmp, src, needle_size) == 0)
			return (dst_tmp);
	}
	return (NULL);
}
