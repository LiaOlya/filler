/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coords.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltkache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 12:13:55 by oltkache          #+#    #+#             */
/*   Updated: 2018/03/24 12:13:55 by oltkache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

unsigned char		ft_num_len(unsigned char num)
{
	unsigned char res;

	res = 0;
	if (num == 0)
		return (1);
	if (num < 0)
		++res;
	while (num >= 1)
	{
		num /= 10;
		++res;
	}
	return (res);
}

int					ft_ignore_case(char a, char b)
{
	if (a == b || a == b + 32 || b == a + 32)
		return (1);
	return (0);
}

int					ft_get_size(unsigned char *x, unsigned char *y, int s)
{
	char *line;

	if (!get_next_line(0, &line))
		return (0);
	*x = ft_atoi(&line[s]);
	*y = ft_atoi(&line[s + ft_num_len(*x) + 1]);
	ft_strdel(&line);
	return (1);
}

void				ft_player(t_m *map)
{
	char *line;

	get_next_line(0, &line);
	if (line[9] == 'p')
	{
		if (line[10] == '1')
		{
			map->pl = 'o';
			map->op = 'x';
		}
		if (line[10] == '2')
		{
			map->pl = 'x';
			map->op = 'o';
		}
	}
	ft_strdel(&line);
}

int					ft_h(char **line)
{
	get_next_line(0, line);
	if (!(*line))
	{
		ft_strdel(line);
		return (0);
	}
	ft_strdel(line);
	return (1);
}
