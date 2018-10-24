/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaznodi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 16:25:02 by vkaznodi          #+#    #+#             */
/*   Updated: 2017/11/23 16:25:03 by vkaznodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ss1;
	unsigned char	*ss2;

	if (s1 == s2 || n == 0)
		return (0);
	ss1 = (unsigned char*)s1;
	ss2 = (unsigned char*)s2;
	while (n > 0)
	{
		if (*ss1 != *ss2)
			return (*ss1 - *ss2);
		if (n > 0)
		{
			ss1++;
			ss2++;
		}
		n--;
	}
	return (0);
}
