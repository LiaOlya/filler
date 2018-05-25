/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vizualizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltkache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 12:11:43 by oltkache          #+#    #+#             */
/*   Updated: 2018/04/26 12:11:44 by oltkache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "viz.h"

char	*ft_first_read(unsigned char *i, unsigned char *j)
{
	char *map;
	char *line;

	while ((*i)++ < 9)
	{
		if (!ft_read(&line))
			return (0);
		ft_strdel(&line);
	}
	map = ft_get_size(i, j, 8);
	return (map);
}

int		ft_1(int ch, unsigned char i)
{
	unsigned char	j;
	char			*line;

	j = 0;
	if (!ft_read(&line))
		return (0);
	ft_out(line, ch);
	j = 0;
	while (j++ < i)
	{
		if (!ft_read(&line))
			return (0);
		ft_out(line, ch);
	}
	ft_get_size(&i, &j, 6);
	j = 0;
	while (j++ < i)
	{
		if (!ft_read(&line))
			return (0);
		ft_strdel(&line);
	}
	return (1);
}

int		ft_2(int ch, char *map, int i, char **argv)
{
	char *line;

	system("clear");
	if (!ft_1(ch, i))
		return (0);
	if (!ft_read(&line))
		return (0);
	ft_strdel(&line);
	if (get_next_line(0, &line) == 0)
	{
		ft_strdel(&line);
		return (0);
	}
	if (ft_strcmp(line, map) != 0)
	{
		ft_strdel(&line);
		ft_strdel(&map);
		return (0);
	}
	if (ft_atoi(argv[2]) == 1)
		usleep(0);
	return (1);
}

int		main(int argc, char **argv)
{
	int				ch;
	unsigned char	i;
	unsigned char	j;
	char			*line;
	char			*map;

	i = 0;
	j = 0;
	ch = 1;
	if (argc > 1)
		ch = ft_atoi(argv[1]);
	map = ft_first_read(&i, &j);
	while (1)
	{
		if (!ft_2(ch, map, i, argv))
			break ;
	}
	j = 0;
	while (get_next_line(0, &line) > 0)
	{
		if (line[0] == '=' && line[1] == '=')
			ft_out(line, 1);
	}
	return (0);
}
