/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 17:27:09 by mcarc             #+#    #+#             */
/*   Updated: 2019/09/23 19:45:39 by mcarc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static void	ft_dellst(void *content, size_t content_size)
{
	(void)content_size;
	free(content);
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*list;
	t_list	*head;

	if (!lst || !f)
		return (NULL);
	tmp = f(lst);
	head = ft_lstnew(tmp->content, tmp->content_size);
	if (!head)
		return (NULL);
	list = head;
	while (lst->next)
	{
		lst = lst->next;
		tmp = f(lst);
		list->next = ft_lstnew(tmp->content, tmp->content_size);
		if (!list->next)
		{
			ft_lstdel(&head, &ft_dellst);
			return (NULL);
		}
		list = list->next;
	}
	return (head);
}
