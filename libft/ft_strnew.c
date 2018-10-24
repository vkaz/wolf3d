/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaznodi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 14:49:55 by vkaznodi          #+#    #+#             */
/*   Updated: 2017/12/01 14:49:57 by vkaznodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*s1;

	s1 = (char*)malloc(size + 1);
	if (s1 == NULL)
		return (NULL);
	ft_memset(s1, '\0', size + 1);
	return (s1);
}
