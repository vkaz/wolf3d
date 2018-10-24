/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaznodi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 15:04:58 by vkaznodi          #+#    #+#             */
/*   Updated: 2018/10/13 15:05:01 by vkaznodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include "mlx.h"
# include <math.h>
# include "libft/libft.h"
# include <errno.h>

typedef struct		s_vec
{
	float			x;
	float			y;
}					t_vec;

typedef struct		s_ivec
{
	int				x;
	int				y;
}					t_ivec;

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	void			*img;
	int				*data;
	int				bpp;
	int				sizeline;
	int				end;
	int				w;
	int				h;
	int				move_up;
	int				move_down;
	int				move_right;
	int				move_left;
	int				s_w;
	int				s_h;
	int				**map;
	int				line_h;
	int				draw_start;
	int				draw_end;
	int				i;
	t_vec			pl_pos;
	t_vec			p_dir;
	t_vec			p_plane;
	t_vec			r_pos;
	t_vec			r_dir;
	t_vec			r_delta;
	t_vec			step;
	t_vec			wall_side;
	t_ivec			r_map;
	t_list			*list;
	t_list			*tmp;
	float			p_z;
	float			rot_s;
	float			speed_move;
	float			r_cam;
	float			hit;
	float			r_dist;
	float			hit_side;
	unsigned int	c1;
	unsigned int	c2;
	unsigned int	c3;
	unsigned int	c4;
	unsigned int	c_s;
	unsigned int	c_g;
	char			**str;
	char			*line;
}					t_mlx;

int					read_file(char *argv, t_mlx *mlx);
void				raycast(t_mlx *mlx);
void				draw_line(t_mlx *mlx, int x);
void				left(t_mlx *mlx);
void				right(t_mlx *mlx);
void				down(t_mlx *mlx);
void				up(t_mlx *mlx);
void				speed(t_mlx *mlx, int c);
void				str_pos(t_mlx *mlx);
void				check_map(t_list *list, t_mlx *mlx);
void				wrong_file(void);
void				errrr(void);

#endif
