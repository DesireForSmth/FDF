/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 14:28:41 by mcarc             #+#    #+#             */
/*   Updated: 2019/09/25 14:47:38 by mcarc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join_str;
	size_t	i;
	size_t	j;
	size_t	len1;
	size_t	len2;

	if (s1 && s2)
	{
		len1 = ft_strlen(s1);
		len2 = ft_strlen(s2);
		i = -1;
		j = 0;
		if (!(join_str = (char *)malloc(sizeof(char) * (len1 + len2 + 1))))
			return (NULL);
		while (++i < len1)
			join_str[i] = s1[i];
		while (j < len2)
			join_str[i++] = s2[j++];
		join_str[i] = '\0';
		return (join_str);
	}
	return (NULL);
}
