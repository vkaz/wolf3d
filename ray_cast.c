/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaznodi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 11:50:52 by vkaznodi          #+#    #+#             */
/*   Updated: 2018/10/19 11:50:53 by vkaznodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		dist1(t_mlx *mlx)
{
	if (mlx->hit_side == 0)
		mlx->r_dist = (mlx->r_map.x - mlx->pl_pos.x + (1 - mlx->step.x)
			/ 2) / mlx->r_dir.x;
	else
		mlx->r_dist = (mlx->r_map.y - mlx->pl_pos.y + (1 - mlx->step.y)
			/ 2) / mlx->r_dir.y;
}

void		dist(t_mlx *mlx)
{
	while (mlx->hit == 0)
	{
		if (mlx->wall_side.x < mlx->wall_side.y)
		{
			mlx->wall_side.x += mlx->r_delta.x;
			mlx->r_map.x += mlx->step.x;
			mlx->hit_side = 0;
		}
		else
		{
			mlx->wall_side.y += mlx->r_delta.y;
			mlx->r_map.y += mlx->step.y;
			mlx->hit_side = 1;
		}
		if (mlx->map[mlx->r_map.x][mlx->r_map.y] > 0)
		{
			mlx->hit = 1;
			dist1(mlx);
		}
	}
}

void		steps(t_mlx *mlx)
{
	if (mlx->r_dir.x < 0)
	{
		mlx->step.x = -1;
		mlx->wall_side.x = (mlx->pl_pos.x - (int)mlx->pl_pos.x)
			* mlx->r_delta.x;
	}
	else
	{
		mlx->step.x = 1;
		mlx->wall_side.x = ((int)mlx->pl_pos.x + 1 - mlx->pl_pos.x)
			* mlx->r_delta.x;
	}
	if (mlx->r_dir.y < 0)
	{
		mlx->step.y = -1;
		mlx->wall_side.y = (mlx->pl_pos.y - (int)mlx->pl_pos.y)
			* mlx->r_delta.y;
	}
	else
	{
		mlx->step.y = 1;
		mlx->wall_side.y = ((int)mlx->pl_pos.y + 1 - mlx->pl_pos.y)
			* mlx->r_delta.y;
	}
}

void		raycast(t_mlx *mlx)
{
	int		i;

	i = 0;
	while (i < mlx->w)
	{
		mlx->r_cam = 2 * i / (float)mlx->w - 1;
		mlx->r_dir.x = mlx->p_dir.x + mlx->p_plane.x * mlx->r_cam;
		mlx->r_dir.y = mlx->p_dir.y + mlx->p_plane.y * mlx->r_cam;
		mlx->r_map = (t_ivec){(int)mlx->pl_pos.x, (int)mlx->pl_pos.y};
		mlx->r_delta.x = sqrt(1 + pow(mlx->r_dir.y, 2) / pow(mlx->r_dir.x, 2));
		mlx->r_delta.y = sqrt(1 + pow(mlx->r_dir.x, 2) / pow(mlx->r_dir.y, 2));
		mlx->hit = 0;
		mlx->r_dist = -1;
		mlx->hit_side = -1;
		steps(mlx);
		dist(mlx);
		draw_line(mlx, i);
		i++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}
