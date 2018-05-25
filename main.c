/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltkache <oltkache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 14:27:30 by oltkache          #+#    #+#             */
/*   Updated: 2018/02/20 12:44:05 by oltkache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <fcntl.h>

void	ft_del(t_m map, t_pc piece)
{
	int i;

	i = 0;
	while (i < map.x)
	{
		ft_strdel((&map.m[i]));
		++i;
	}
	i = 0;
	while (i < piece.x)
	{
		ft_strdel((&piece.p[i]));
		++i;
	}
	free(map.m);
	free(piece.p);
}

void	ft_del_list(t_coor **coor)
{
	t_coor *next;
	t_coor *head;

	head = *coor;
	while (head)
	{
		next = head->next;
		free(head);
		head = next;
	}
	*coor = NULL;
}

void	ft_out(t_c t)
{
	char	*x;
	char	*y;

	x = ft_itoa(t.x);
	y = ft_itoa(t.y);
	write(1, x, ft_strlen(x));
	write(1, " ", 1);
	write(1, y, ft_strlen(y));
	write(1, "\n", 1);
	ft_strdel(&x);
	ft_strdel(&y);
}

int		ft_alg(t_m *map, t_pc *piece)
{
	t_c		t;
	t_coor	*coor;
	t_coor	*opon;

	coor = NULL;
	opon = NULL;
	t.x = 0;
	t.y = 0;
	if (!ft_read_map(map, &opon))
		return (0);
	ft_piece(piece);
	ft_itarate_map(*map, &coor, *piece);
	if (!coor)
		ft_coor_add(0, 0, &coor);
	ft_find_best(coor, opon, &t);
	ft_out(t);
	ft_del(*map, *piece);
	ft_del_list(&coor);
	ft_del_list(&opon);
	return (1);
}

int		main(void)
{
	t_pc	piece;
	int		g;
	t_m		map;

	g = 0;
	while (1)
	{
		map.m = NULL;
		piece.p = NULL;
		if (g == 0)
		{
			ft_player(&map);
			g = 1;
		}
		if (!ft_alg(&map, &piece))
			return (0);
	}
	return (0);
}
