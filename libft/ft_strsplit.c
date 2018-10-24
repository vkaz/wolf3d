/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaznodi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 14:55:28 by vkaznodi          #+#    #+#             */
/*   Updated: 2017/12/01 14:55:29 by vkaznodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_len(char const *s, char c)
{
	size_t		i;
	size_t		count;

	i = 0;
	count = 0;
	if (s[i] == c)
		i++;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		count++;
	}
	return (count);
}

static size_t	words(char const *s, char c)
{
	size_t		i;
	size_t		count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
			count++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (count);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t		i;
	size_t		j;
	size_t		cw;
	char		**str;

	if (!s)
		return (NULL);
	cw = words(s, c);
	j = 0;
	i = 0;
	if (!(str = (char**)malloc(sizeof(char*) * (cw + 1))))
		return (NULL);
	while (cw--)
	{
		while (*s == c && *s)
			s++;
		j = get_len((char*)s, c);
		if (!(str[i] = ft_strsub((const char*)s, 0, j)))
			return (NULL);
		s += j;
		i++;
	}
	str[i] = NULL;
	return (str);
}
