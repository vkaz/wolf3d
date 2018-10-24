/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaznodi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 14:54:16 by vkaznodi          #+#    #+#             */
/*   Updated: 2017/12/01 14:54:20 by vkaznodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	char		*str;

	i = 0;
	if (s)
	{
		str = (char*)malloc(sizeof(*str) * len + 1);
		if (!str)
			return (NULL);
		while (i < len)
			str[i++] = s[start++];
		str[i] = '\0';
		return ((char*)str);
	}
	return (NULL);
}
