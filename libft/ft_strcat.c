/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaznodi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 12:24:12 by vkaznodi          #+#    #+#             */
/*   Updated: 2017/11/16 12:24:13 by vkaznodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dst, const char *src)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = (int)ft_strlen(dst);
	while (src[i] != '\0')
		dst[j++] = src[i++];
	dst[j] = '\0';
	return (dst);
}
