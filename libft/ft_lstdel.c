/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaznodi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 15:41:40 by vkaznodi          #+#    #+#             */
/*   Updated: 2017/12/29 15:41:42 by vkaznodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list		*list;
	t_list		*next_list;

	if (alst && del)
	{
		list = *alst;
		while (list)
		{
			next_list = list->next;
			del(list->content, list->content_size);
			free(list);
			list = next_list;
		}
		*alst = NULL;
	}
}
