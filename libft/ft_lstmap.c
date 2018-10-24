/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaznodi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 15:42:39 by vkaznodi          #+#    #+#             */
/*   Updated: 2017/12/29 15:42:40 by vkaznodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*list;
	t_list		*new;
	t_list		*res;

	if (!lst || !f)
		return (NULL);
	list = f(lst);
	if (!(new = ft_lstnew(list->content, list->content_size)))
		return (NULL);
	lst = lst->next;
	res = new;
	while (lst)
	{
		list = f(lst);
		if (!(new->next = ft_lstnew(list->content, list->content_size)))
			return (NULL);
		new = new->next;
		lst = lst->next;
	}
	return (res);
}
