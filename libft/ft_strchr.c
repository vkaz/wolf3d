/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaznodi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 14:27:50 by vkaznodi          #+#    #+#             */
/*   Updated: 2017/12/14 14:27:51 by vkaznodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int ch)
{
	char	*s;

	s = (char*)str;
	while (*s)
	{
		if (*s == (char)ch)
			return (s);
		s++;
	}
	if ((char)ch == 0)
		return (s);
	return (NULL);
}
