/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaznodi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 13:06:56 by vkaznodi          #+#    #+#             */
/*   Updated: 2017/11/23 13:06:58 by vkaznodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check(char *str, size_t res, int s)
{
	while (*str >= '0' && *str <= '9')
	{
		if ((res > 922337203685477580 || (res == 922337203685477580 && (*str
			- '0') > 7)) && s == 1)
			return (-1);
		else if ((res > 922337203685477580 || (res == 922337203685477580
			&& (*str - '0') > 8)) && s == -1)
			return (0);
		res = res * 10 + *str - '0';
		str++;
	}
	return (res);
}

int			ft_atoi(char *str)
{
	size_t			res;
	int				s;

	res = 0;
	s = 1;
	while (*str == '\t' || *str == '\n' || *str == '\v' || *str == '\f'
		|| *str == '\r' || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			s = -1;
		str++;
	}
	res = check(str, res, s);
	return (res * s);
}
