/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaznodi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 14:23:30 by vkaznodi          #+#    #+#             */
/*   Updated: 2017/11/11 14:23:31 by vkaznodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(char *src)
{
	size_t		i;
	size_t		strlen;
	char		*strdup;

	strlen = ft_strlen(src);
	if (!(strdup = (char *)malloc(strlen + 1)))
		return (NULL);
	i = 0;
	while (i <= strlen)
	{
		strdup[i] = src[i];
		i++;
	}
	return (strdup);
}
