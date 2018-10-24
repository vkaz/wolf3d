/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaznodi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 17:55:03 by vkaznodi          #+#    #+#             */
/*   Updated: 2017/12/21 17:55:05 by vkaznodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		get_len(int n)
{
	int		i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

char			*ft_itoa(int n)
{
	unsigned int	n_c;
	size_t			len;
	char			*str;

	len = get_len(n);
	if (n < 0)
	{
		n_c = -n;
		len = len + 1;
	}
	else if (n >= 0)
		n_c = n;
	if (!(str = ft_strnew(len)))
		return (NULL);
	str[--len] = n_c % 10 + '0';
	while (n_c /= 10)
		str[--len] = n_c % 10 + '0';
	if (n < 0)
		*(str + 0) = '-';
	return (str);
}
