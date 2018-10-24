/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaznodi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 12:14:34 by vkaznodi          #+#    #+#             */
/*   Updated: 2017/11/30 12:14:36 by vkaznodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *arr, int c, size_t n)
{
	unsigned char		*s1;
	unsigned char		s2;
	unsigned long		i;

	s1 = (unsigned char*)arr;
	s2 = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (s1[i] == s2)
			return ((void *)s1 + i);
		i++;
	}
	return (NULL);
}
