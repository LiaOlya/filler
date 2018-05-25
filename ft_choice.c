/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_choice.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltkache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 10:12:27 by oltkache          #+#    #+#             */
/*   Updated: 2018/03/25 10:12:28 by oltkache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_coor_add(int x, int y, t_coor **coor)
{
	t_coor	*add;

	if (!(*coor))
	{
		*coor = (t_coor*)malloc(sizeof(t_coor));
		(*coor)->next = NULL;
		(*coor)->x = x;
		(*coor)->y = y;
		return ;
	}
	add = (t_coor*)malloc(sizeof(t_coor));
	add->x = x;
	add->y = y;
	add->next = NULL;
	if (add && coor)
	{
		add->next = *coor;
		*coor = add;
	}
}

void	ft_iter_piece(t_m map, t_c t, t_coor **coor, t_pc piece)
{
	int my;
	int op;
	int i;
	int j;

	i = -1;
	my = 0;
	op = 0;
	while (++i < piece.x)
	{
		j = -1;
		while (++j < piece.y)
			if (piece.p[i][j] == 1)
			{
				if (ft_ignore_case(map.pl, map.m[t.x + i][t.y + j]))
					my += 1;
				else if (ft_ignore_case(map.op, map.m[t.x + i][t.y + j]))
					op += 1;
			}
	}
	if (my == 1 && op == 0)
		ft_coor_add(t.x, t.y, coor);
}

void	ft_itarate_map(t_m map, t_coor **coor, t_pc piece)
{
	t_c t;

	t.x = 0;
	while (t.x + piece.x <= map.x)
	{
		t.y = 0;
		while (t.y + piece.y <= map.y)
		{
			ft_iter_piece(map, t, coor, piece);
			++t.y;
		}
		++t.x;
	}
}

int		ft_dist(int a, int b)
{
	if (a > b)
		return (a - b);
	return (b - a);
}

void	ft_find_best(t_coor *coor, t_coor *opon, t_c *t)
{
	int		dist;
	int		d;
	t_coor	*h1;
	t_coor	*h2;

	t->x = coor->x;
	t->y = coor->y;
	d = ft_dist(coor->x, opon->x) + ft_dist(coor->y, opon->y);
	h1 = coor;
	while (h1)
	{
		h2 = opon;
		while (h2)
		{
			dist = ft_dist(h1->x, h2->x) + ft_dist(h1->y, h2->y);
			if (dist <= d)
			{
				d = dist;
				t->x = h1->x;
				t->y = h1->y;
			}
			h2 = h2->next;
		}
		h1 = h1->next;
	}
}
