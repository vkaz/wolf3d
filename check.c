/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaznodi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 17:01:51 by vkaznodi          #+#    #+#             */
/*   Updated: 2018/10/19 17:01:52 by vkaznodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		wrong_file(void)
{
	printf("\033[31mWrong file\n");
	exit(1);
}

void		check_map(t_list *list, t_mlx *mlx)
{
	int		h;
	int		w;

	w = 0;
	while (list)
	{
		h = ft_strlen(list->content);
		list = list->next;
		w++;
	}
	if ((h != (mlx->s_w * 2) - 1) || (w != mlx->s_h))
		wrong_file();
}

int			getnum(char *str)
{
	int		ret;

	if (*str == '-')
		return (-getnum(str + 1));
	if (*str == '+')
		return (getnum(str + 1));
	ret = 0;
	while (*str && *str >= '0' && *str <= '9')
	{
		ret *= 10;
		ret = ret + *str - '0';
		str++;
	}
	return (ret);
}

void		pos(char **str, t_mlx *mlx)
{
	int i;

	if (str[0] != NULL && str[1] != NULL)
	{
		mlx->s_w = getnum(str[0]);
		mlx->s_h = getnum(str[1]);
		if ((mlx->s_w != mlx->s_h) || mlx->s_w < 4)
			wrong_file();
	}
	if (str[2] != NULL && str[3] != NULL)
	{
		mlx->pl_pos = (t_vec){getnum(str[2]) + 0.5, getnum(str[3]) + 0.5};
		if (mlx->pl_pos.x < 1.5 || (mlx->pl_pos.x) > mlx->s_w)
			mlx->pl_pos.x = 1.5;
		if (mlx->pl_pos.y < 1.5 || (mlx->pl_pos.y) >= mlx->s_h)
			mlx->pl_pos.y = 1.5;
	}
	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}

void		str_pos(t_mlx *mlx)
{
	mlx->str = ft_strsplit(mlx->line, ' ');
	free(mlx->line);
	pos(mlx->str, mlx);
}
