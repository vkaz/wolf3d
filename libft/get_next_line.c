/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaznodi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 19:05:22 by vkaznodi          #+#    #+#             */
/*   Updated: 2018/01/24 19:05:23 by vkaznodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		op(char **str, char *buf)
{
	if (ft_strlen(*str) == 0)
		return (-2);
	*str = ft_strjoin(*str, "\n");
	free(buf);
	return (0);
}

static int		read_file(int fd, char **str)
{
	char				*buf;
	char				*d;
	int					i;

	buf = ft_strnew(BUFF_SIZE);
	if ((i = read(fd, buf, BUFF_SIZE)) < 0)
		return (-1);
	d = NULL;
	buf[i] = '\0';
	if (i > 0)
	{
		d = ft_strdup(*str);
		ft_memdel((void**)str);
		*str = ft_strjoin(d, buf);
		ft_memdel((void**)&d);
	}
	free(buf);
	buf = *str;
	if (i == 0)
		if (op(str, buf) == -2)
			return (-2);
	return (i);
}

int				get_next_line(const int fd, char **line)
{
	static char		*str;
	char			*end;
	int				c;

	if (!str)
		str = ft_strnew(BUFF_SIZE);
	end = ft_strchr(str, '\n');
	while (end == NULL)
	{
		c = read_file(fd, &str);
		if (c < 0)
		{
			if ((c == -2) && (end = ft_strchr(str, '\0')) == str)
				return (0);
			return (-1);
		}
		else
			end = ft_strchr(str, '\n');
	}
	*line = ft_strsub(str, 0, (ft_strlen(str) - ft_strlen(end)));
	end = ft_strdup(end + 1);
	free(str);
	str = end;
	return (1);
}
