/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaznodi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 18:37:03 by vkaznodi          #+#    #+#             */
/*   Updated: 2017/08/03 18:37:05 by vkaznodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_range(int min, int max)
{
	int *mas;
	int a;

	if (min >= max)
		return (NULL);
	if (!(mas = (int*)malloc(sizeof(max - min))))
		return (NULL);
	a = 0;
	while (a < (max - min))
	{
		mas[a] = (min + a);
		a++;
	}
	return (mas);
}
