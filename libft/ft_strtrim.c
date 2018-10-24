/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaznodi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 14:55:12 by vkaznodi          #+#    #+#             */
/*   Updated: 2017/12/01 14:55:14 by vkaznodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char			*str;
	int				i;
	int				c;
	int				a;

	c = -1;
	a = 0;
	if (s == NULL)
		return (NULL);
	i = ft_strlen((char*)s);
	while (s[i - 1] == ' ' || s[i - 1] == '\n' || s[i - 1] == '\t')
		i--;
	while (s[++c] == ' ' || s[c] == '\n' || s[c] == '\t')
		i--;
	if (i <= 0)
		i = 0;
	if ((str = (char*)malloc(sizeof(char) * (i + 1))) == NULL)
		return (NULL);
	while (a < i)
		str[a++] = s[c++];
	str[a] = '\0';
	return (str);
}
