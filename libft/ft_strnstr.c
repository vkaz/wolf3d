/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaznodi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 13:25:29 by vkaznodi          #+#    #+#             */
/*   Updated: 2017/11/16 13:25:30 by vkaznodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *str, const char *to_find, int len)
{
	int		a;
	int		b;
	size_t	c;
	size_t	cou;

	a = 0;
	cou = 0;
	while (to_find[cou] != '\0')
		cou++;
	if (cou == 0)
		return (str);
	while (str[a] != '\0' && a < len)
	{
		b = a;
		c = 0;
		while (str[b] == to_find[c] && b < len && str[b] && to_find[c])
		{
			b++;
			c++;
		}
		if (to_find[c] == '\0')
			return (&str[b - c]);
		a++;
	}
	return (0);
}
