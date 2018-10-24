/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaznodi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 13:58:37 by vkaznodi          #+#    #+#             */
/*   Updated: 2017/11/10 13:58:39 by vkaznodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memset(void *dst, int c, size_t n)
{
	unsigned char		*s;
	size_t				i;

	if (n == 0)
		return (dst);
	i = 0;
	s = (unsigned char*)dst;
	while (i < n)
	{
		((char *)dst)[i] = (unsigned char)c;
		i++;
	}
	return (dst);
}
