/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaznodi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 15:27:19 by vkaznodi          #+#    #+#             */
/*   Updated: 2017/12/29 15:27:20 by vkaznodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*list;
	void		*tmp;

	if (!(tmp = (void *)ft_memalloc(content_size + 1)))
		return (NULL);
	if (!(list = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		tmp = NULL;
		content_size = 0;
	}
	else
		tmp = ft_memcpy(tmp, (void*)content, content_size);
	if (list != NULL)
	{
		list->content_size = content_size;
		list->next = NULL;
		list->content = tmp;
	}
	return (list);
}
