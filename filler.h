/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltkache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 17:38:40 by oltkache          #+#    #+#             */
/*   Updated: 2018/03/23 17:38:41 by oltkache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FILLER_H
# define __FILLER_H

# include "libft/get_next_line.h"

/*
**map
*/
typedef struct	s_m
{
	unsigned char	x;
	unsigned char	y;
	char			pl;
	char			op;
	char			**m;
}				t_m;

/*
**piece
*/
typedef struct	s_pc
{
	int				i0;
	int				i1;
	int				j0;
	int				j1;
	unsigned char	x;
	unsigned char	y;
	char			**p;
}				t_pc;

typedef struct	s_c
{
	unsigned char	x;
	unsigned char	y;
}				t_c;

typedef struct	s_coor
{
	unsigned char	x;
	unsigned char	y;
	struct s_coor	*next;
}				t_coor;

void			ft_coor_add(int x, int y, t_coor **coor);
void			ft_iter_piece(t_m map, t_c t, t_coor **coor, t_pc piece);
void			ft_itarate_map(t_m map, t_coor **coor, t_pc piece);
void			ft_find_best(t_coor *coor, t_coor *opon, t_c *t);

int				ft_ignore_case(char a, char b);
int				ft_get_size(unsigned char *x, unsigned char *y, int s);
void			ft_player(t_m *map);
int				ft_h(char **line);

void			ft_piece(t_pc *piece);
void			ft_oponent(t_m *map, char line, t_c t, t_coor **opon);
int				ft_read_map(t_m *map, t_coor **opon);

#endif
