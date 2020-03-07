/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 16:16:03 by mcarc             #+#    #+#             */
/*   Updated: 2019/09/25 14:43:55 by mcarc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char			*ft_strdup(const char *s1)
{
	const char	*tmp;
	char		*s2;
	char		*s3;
	size_t		str_len;

	str_len = ft_strlen(s1);
	tmp = s1;
	if (str_len < str_len + 1)
	{
		s2 = (char *)ft_memalloc(sizeof(char) * (str_len + 1));
		if (s2 == 0)
			return (NULL);
		s3 = s2;
		while (str_len--)
		{
			*s2++ = *tmp++;
		}
		*s2 = '\0';
		return (s3);
	}
	return (0);
}
