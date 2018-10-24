/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaznodi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 11:44:09 by vkaznodi          #+#    #+#             */
/*   Updated: 2018/09/24 11:44:11 by vkaznodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		errrr(void)
{
	perror("\033[31mFile opening error");
	exit(1);
}

void		map(char *str, t_mlx *mlx, int a)
{
	char	**split;
	int		i;

	i = 0;
	mlx->map[a] = (int*)malloc(sizeof(int) * mlx->s_h);
	split = ft_strsplit(str, ' ');
	while (split[i])
	{
		mlx->map[a][i] = ft_atoi(split[i]);
		if ((a == 0 || a == mlx->s_h - 1) && mlx->map[a][i] != 1)
			wrong_file();
		if ((i == 0 || i == mlx->s_h - 1) && mlx->map[a][i] != 1)
			wrong_file();
		if (mlx->map[a][i] < 0 || mlx->map[a][i] > 1)
			mlx->map[a][i] = 0;
		i++;
	}
	i = -1;
	while (split[++i])
		free(split[i]);
	free(split);
}

void		flist(t_list *list)
{
	t_list		*tmp;

	while (list != NULL)
	{
		tmp = list;
		free(list->content);
		list = list->next;
		free(tmp);
	}
}

int			read_file(char *argv, t_mlx *mlx)
{
	int		fd;
	t_list	*list;
	t_list	*tmp;

	fd = open(argv, O_RDONLY);
	if (fd < 0 || (get_next_line(fd, &mlx->line) < 1))
		return (-1);
	str_pos(mlx);
	while (get_next_line(fd, &mlx->line) == 1)
	{
		ft_lstpushback(&list, mlx->line, ft_strlen(mlx->line));
		free(mlx->line);
	}
	close(fd);
	check_map(list, mlx);
	mlx->map = (int**)malloc(sizeof(int*) * mlx->s_w);
	tmp = list;
	while (list && mlx->i < mlx->s_w)
	{
		map(list->content, mlx, mlx->i);
		list = list->next;
		mlx->i++;
	}
	flist(tmp);
	return (0);
}
