/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 14:48:40 by mcarc             #+#    #+#             */
/*   Updated: 2019/09/23 19:45:39 by mcarc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int		word_count(const char *str, char c)
{
	int k;

	k = 0;
	while (*str)
	{
		while (*str == c)
			str++;
		if (*str != '\0')
			k++;
		while (*str != c && *str != '\0')
			str++;
	}
	return (k);
}

static int		word_size(const char *str, char c)
{
	int i;

	i = 0;
	while (*str != c && *str)
	{
		str++;
		i++;
	}
	return (i);
}

static int		word_new(char const *str, char **tab, int i, int s)
{
	tab[i] = ft_strnew(s);
	if (tab[i] == 0)
	{
		while (i >= 0)
		{
			i--;
			ft_memdel((void *)tab[i]);
		}
		ft_memdel((void **)tab[i]);
		return (0);
	}
	ft_strncpy(tab[i], str, s);
	return (1);
}

char			**ft_strsplit(char const *str, char c)
{
	int		k;
	int		s;
	int		i;
	char	**tab;

	i = -1;
	if (str == 0)
		return (NULL);
	k = word_count(str, c);
	tab = (char**)malloc(sizeof(char*) * (k + 1));
	if (tab == 0)
		return (NULL);
	while (i++ < k - 1)
	{
		while (*str == c)
			str++;
		s = word_size(str, c);
		if (word_new(str, tab, i, s) == 0)
			return (0);
		while (*str != c && *str != '\0')
			str++;
	}
	tab[i] = 0;
	return (tab);
}
