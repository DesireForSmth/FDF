/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_create_node.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 19:07:43 by mcarc             #+#    #+#             */
/*   Updated: 2019/09/30 11:46:49 by mcarc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_btree	*ft_btree_create_node(void *item)
{
	t_btree *tmp;

	tmp = (t_btree *)malloc(sizeof(t_btree));
	if (tmp)
	{
		tmp->left = NULL;
		tmp->right = NULL;
		tmp->item = item;
	}
	return (tmp);
}
