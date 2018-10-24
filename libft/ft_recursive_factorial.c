/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaznodi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/29 12:06:45 by vkaznodi          #+#    #+#             */
/*   Updated: 2017/07/29 18:05:06 by vkaznodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_recursive_factorial(int nb)
{
	int r;

	r = 1;
	if (nb < 0 || nb > 12)
	{
		return (0);
	}
	if (nb > 0)
	{
		r = nb * ft_recursive_factorial(nb - 1);
	}
	return (r);
}
