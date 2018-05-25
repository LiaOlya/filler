/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltkache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 17:05:58 by oltkache          #+#    #+#             */
/*   Updated: 2018/04/23 17:05:59 by oltkache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_get_p(t_pc *piece, int k, int j)
{
	piece->p[k][j] = 1;
}

void	ft_piece(t_pc *piece)
{
	char	*line;
	int		i;
	int		k;
	int		j;

	i = -1;
	ft_get_size(&piece->x, &piece->y, 6);
	piece->p = (char**)malloc(sizeof(char*) * piece->x);
	k = -1;
	while (++i < piece->x)
	{
		get_next_line(0, &line);
		j = -1;
		piece->p[++k] = (char*)malloc(sizeof(char) * piece->y);
		while (++j < piece->y)
		{
			if (line[j] == '*')
				ft_get_p(piece, k, j);
			else if (line[j] == '.')
				piece->p[k][j] = 0;
		}
		ft_strdel(&line);
	}
}

void	ft_oponent(t_m *map, char line, t_c t, t_coor **opon)
{
	if (line == 46)
		map->m[t.x][t.y] = 0;
	else
	{
		map->m[t.x][t.y] = line;
		if (ft_ignore_case(map->op, line))
			ft_coor_add(t.x, t.y, opon);
	}
}

int		ft_read_map(t_m *map, t_coor **opon)
{
	t_c		t;
	int		j;
	char	*line;

	t.x = -1;
	if (!ft_get_size(&map->x, &map->y, 8))
		return (0);
	if (!ft_h(&line))
		return (0);
	map->m = (char**)malloc(sizeof(char*) * map->x);
	while (++t.x < map->x && get_next_line(0, &line) > 0)
	{
		t.y = -1;
		j = -1;
		while (line[++j])
			if (!((line[j] >= 48 && line[j] <= 57) || line[j] == ' '))
				break ;
		map->m[t.x] = (char*)malloc(sizeof(char) * (map->y + 1));
		map->m[t.x][map->y] = '\0';
		while (++t.y < map->y && line[j])
			ft_oponent(map, line[j++], t, opon);
		ft_strdel(&line);
	}
	return (1);
}
