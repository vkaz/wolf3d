/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaznodi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 18:44:12 by vkaznodi          #+#    #+#             */
/*   Updated: 2018/10/18 18:44:13 by vkaznodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	speed(t_mlx *mlx, int c)
{
	if (c == 1)
	{
		if (mlx->speed_move < 0.1)
		{
			mlx->rot_s += 0.01;
			mlx->speed_move += 0.01;
		}
	}
	else
	{
		if (mlx->speed_move > 0.01)
		{
			mlx->rot_s -= 0.01;
			mlx->speed_move -= 0.01;
		}
	}
}

void	up(t_mlx *mlx)
{
	if (mlx->map[(int)(mlx->pl_pos.x + mlx->p_dir.x * mlx->speed_move)]
			[(int)mlx->pl_pos.y] == 0)
		mlx->pl_pos.x += mlx->p_dir.x * mlx->speed_move;
	if (mlx->map[(int)mlx->pl_pos.x][(int)(mlx->pl_pos.y + mlx->p_dir.y *
				mlx->speed_move)] == 0)
		mlx->pl_pos.y += mlx->p_dir.y * mlx->speed_move;
}

void	down(t_mlx *mlx)
{
	if (mlx->map[(int)(mlx->pl_pos.x - mlx->p_dir.x * mlx->speed_move)]
			[(int)mlx->pl_pos.y] == 0)
		mlx->pl_pos.x -= mlx->p_dir.x * mlx->speed_move;
	if (mlx->map[(int)mlx->pl_pos.x][(int)(mlx->pl_pos.y - mlx->p_dir.y *
				mlx->speed_move)] == 0)
		mlx->pl_pos.y -= mlx->p_dir.y * mlx->speed_move;
}

void	right(t_mlx *mlx)
{
	t_vec	old_dir;

	old_dir.x = mlx->p_dir.x;
	mlx->p_dir.x = mlx->p_dir.x * cos(-mlx->rot_s) -
		mlx->p_dir.y * sin(-mlx->rot_s);
	mlx->p_dir.y = old_dir.x * sin(-mlx->rot_s) + mlx->p_dir.y *
		cos(-mlx->rot_s);
	old_dir.x = mlx->p_plane.x;
	mlx->p_plane.x = mlx->p_plane.x * cos(-mlx->rot_s) -
		mlx->p_plane.y * sin(-mlx->rot_s);
	mlx->p_plane.y = old_dir.x * sin(-mlx->rot_s) + mlx->p_plane.y *
		cos(-mlx->rot_s);
}

void	left(t_mlx *mlx)
{
	t_vec	old_dir;

	old_dir.x = mlx->p_dir.x;
	mlx->p_dir.x = mlx->p_dir.x * cos(mlx->rot_s) -
		mlx->p_dir.y * sin(mlx->rot_s);
	mlx->p_dir.y = old_dir.x * sin(mlx->rot_s) + mlx->p_dir.y *
		cos(mlx->rot_s);
	old_dir.x = mlx->p_plane.x;
	mlx->p_plane.x = mlx->p_plane.x * cos(mlx->rot_s) -
		mlx->p_plane.y * sin(mlx->rot_s);
	mlx->p_plane.y = old_dir.x * sin(mlx->rot_s) + mlx->p_plane.y *
		cos(mlx->rot_s);
}
