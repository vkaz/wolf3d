/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaznodi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 12:02:39 by vkaznodi          #+#    #+#             */
/*   Updated: 2017/11/16 12:02:40 by vkaznodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	char	*c;

	c = (char*)str + ft_strlen((char*)str);
	while (*c != ch)
	{
		if (c == str)
			return (NULL);
		c--;
	}
	return (c);
}
