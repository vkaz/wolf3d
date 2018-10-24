/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaznodi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 11:56:58 by vkaznodi          #+#    #+#             */
/*   Updated: 2017/11/16 11:57:00 by vkaznodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(char *str, char *to_find)
{
	size_t		i;
	size_t		c;
	size_t		l;

	i = 0;
	l = 0;
	while (to_find[l] != '\0')
		l++;
	if (l == 0)
		return ((char*)str);
	while (str[i])
	{
		c = 0;
		while (str[i + c] == to_find[c])
		{
			if (to_find[c + 1] == '\0')
				return ((char*)str + i);
			c++;
		}
		i++;
	}
	return (0);
}
