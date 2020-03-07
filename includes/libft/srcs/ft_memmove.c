/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 15:09:09 by mcarc             #+#    #+#             */
/*   Updated: 2019/09/23 19:45:39 by mcarc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void				*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;
	unsigned char	*d1;
	unsigned char	*s1;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	d1 = d + len - 1;
	s1 = s + len - 1;
	if (dst == 0 && src == 0)
		return (NULL);
	if (d < s)
		while (len--)
			*d++ = *s++;
	else
	{
		while (len--)
			*d1-- = *s1--;
	}
	return (dst);
}
