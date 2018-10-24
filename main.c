/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaznodi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 15:04:32 by vkaznodi          #+#    #+#             */
/*   Updated: 2018/10/13 15:04:33 by vkaznodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int				mouse_hook(void)
{
	exit(1);
	return (0);
}

int				key_move(int k, t_mlx *mlx)
{
	if (k == 126 || k == 13)
		mlx->move_up = !mlx->move_up;
	if (k == 125 || k == 1)
		mlx->move_down = !mlx->move_down;
	if (k == 123 || k == 0)
		mlx->move_left = !mlx->move_left;
	if (k == 124 || k == 2)
		mlx->move_right = !mlx->move_right;
	if (k == 69 || k == 24)
		speed(mlx, 1);
	if (k == 78 || k == 27)
		speed(mlx, -1);
	if (k == 53)
		exit(1);
	return (0);
}

int				move(t_mlx *mlx)
{
	if (mlx->move_left != 0)
		left(mlx);
	if (mlx->move_down != 0)
		down(mlx);
	if (mlx->move_right != 0)
		right(mlx);
	if (mlx->move_up != 0)
		up(mlx);
	raycast(mlx);
	return (0);
}

void			init(t_mlx *mlx)
{
	mlx->w = 1080;
	mlx->h = 720;
	mlx->c1 = 0x002570;
	mlx->c2 = 0x00704a;
	mlx->c3 = 0x6a6d03;
	mlx->c4 = 0x6d026b;
	mlx->c_s = 0x0090ff;
	mlx->c_g = 0x664848;
	mlx->p_dir.x = -1;
	mlx->p_dir.y = 0;
	mlx->p_z = 0;
	mlx->p_plane.x = 0;
	mlx->p_plane.y = 1;
	mlx->rot_s = 0.04;
	mlx->speed_move = 0.04;
	mlx->move_up = 0;
	mlx->move_down = 0;
	mlx->move_right = 0;
	mlx->move_left = 0;
	mlx->mlx = mlx_init();
	mlx->img = mlx_new_image(mlx->mlx, mlx->w, mlx->h);
	mlx->data = (int*)mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->sizeline,
		&mlx->end);
}

int				main(int argc, char **argv)
{
	t_mlx	mlx;
	int		fd;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if ((read(fd, NULL, 0)) == -1)
			errrr();
		mlx.i = 0;
		if (read_file(argv[1], &mlx) == -1)
			errrr();
		init(&mlx);
		mlx.win = mlx_new_window(mlx.mlx, mlx.w, mlx.h, "Wolf3d");
		mlx_do_key_autorepeatoff(mlx.mlx);
		mlx_key_hook(mlx.win, key_move, &mlx);
		mlx_hook(mlx.win, 2, (1L << 0), key_move, &mlx);
		mlx_hook(mlx.win, 17, 1L << 17, mouse_hook, 0);
		mlx_loop_hook(mlx.mlx, move, &mlx);
		mlx_loop(mlx.mlx);
	}
	else
		printf("\033[31mError\n\033[33mUsage: ./wolf3d map/\n");
	return (0);
}
