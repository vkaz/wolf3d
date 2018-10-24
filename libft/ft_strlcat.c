/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaznodi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 14:27:38 by vkaznodi          #+#    #+#             */
/*   Updated: 2017/12/14 14:27:39 by vkaznodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	n;
	size_t	len;
	size_t	i;

	i = 0;
	n = 0;
	len = ft_strlen((char*)src);
	while (dst[i] && i < size)
		i++;
	while (src[n] && (i + n + 1) < size)
	{
		dst[i + n] = src[n];
		n++;
	}
	if (i != size)
		dst[i + n] = '\0';
	return (i + len);
}
