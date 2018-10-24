/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaznodi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 18:44:04 by vkaznodi          #+#    #+#             */
/*   Updated: 2018/10/18 18:44:05 by vkaznodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

unsigned int	wall(t_mlx *mlx)
{
	if ((mlx->step.x == -1 && mlx->step.y == -1) ||
		(mlx->step.x == 1 && mlx->step.y == -1))
		return (mlx->c1);
	if ((mlx->step.x == -1 && mlx->step.y == 1) ||
		(mlx->step.x == 1 && mlx->step.y == 1))
		return (mlx->c2);
	return (0);
}

void			put_pxl(t_mlx *mlx, int x, int y, unsigned int c)
{
	int		i;

	if (c != mlx->c_s && c != mlx->c_g)
	{
		if (mlx->hit_side == 1)
			c = wall(mlx);
		else if ((mlx->step.x == -1 && mlx->step.y == -1) ||
			(mlx->step.x == -1 && mlx->step.y == 1))
			c = mlx->c3;
		else
			c = mlx->c4;
	}
	i = (y * mlx->w + x);
	if (i <= mlx->w * mlx->h)
		mlx->data[i] = c;
}

void			draw_line(t_mlx *mlx, int x)
{
	int				y;
	unsigned int	c;

	mlx->line_h = (int)(mlx->h / mlx->r_dist);
	mlx->draw_start = -mlx->line_h / 2 + mlx->h / 2;
	if (mlx->draw_start < 0)
		mlx->draw_start = 0;
	mlx->draw_end = mlx->line_h / 2 + mlx->h / 2;
	if (mlx->draw_end >= mlx->h)
		mlx->draw_end = mlx->h - 1;
	c = 0x111111;
	y = -1;
	while (++y < mlx->draw_start + mlx->p_z)
		put_pxl(mlx, x, y, mlx->c_s);
	y -= 1;
	while (y++ <= mlx->draw_end + mlx->p_z && y < mlx->h)
		put_pxl(mlx, x, y, c);
	y -= 1;
	while (y++ <= mlx->h)
		put_pxl(mlx, x, y, mlx->c_g);
}
