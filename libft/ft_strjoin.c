/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaznodi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 14:54:54 by vkaznodi          #+#    #+#             */
/*   Updated: 2017/12/01 14:54:55 by vkaznodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*str;
	size_t			i;
	size_t			c;
	size_t			c1;

	i = 0;
	if (s1 && s2)
	{
		c = ft_strlen((char*)s1);
		c1 = ft_strlen((char*)s2);
		if (!(str = ft_strnew(c + c1)))
			return (NULL);
		while (*s1)
			str[i++] = *s1++;
		while (*s2)
			str[i++] = *s2++;
		str[i] = '\0';
		return ((char*)str);
	}
	return (NULL);
}
