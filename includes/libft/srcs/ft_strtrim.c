/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 14:39:17 by mcarc             #+#    #+#             */
/*   Updated: 2019/09/23 19:45:39 by mcarc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static void			ft_cpy(char *str, const char *s, size_t len)
{
	size_t	i;

	i = 0;
	while (*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	while (i < len)
	{
		str[i] = *s;
		s++;
		i++;
	}
}

char				*ft_strtrim(char const *s)
{
	size_t			l;
	size_t			k;
	char			*str;
	const char		*tmp;

	l = 0;
	if (!s)
		return (NULL);
	tmp = s;
	k = ft_strlen(s);
	while ((s[l] == ' ' || s[l] == '\n' || s[l] == '\t') && s[l] != '\0')
		l++;
	while (s[k - 1] == ' ' || s[k - 1] == '\n' || s[k - 1] == '\t')
		k--;
	if (k < l)
		k = l;
	str = ft_strnew(k - l);
	if (!str)
		return (NULL);
	ft_cpy(str, tmp, k - l);
	return (str);
}
