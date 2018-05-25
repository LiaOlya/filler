/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viz1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltkache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 17:58:33 by oltkache          #+#    #+#             */
/*   Updated: 2018/04/26 17:58:33 by oltkache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "viz.h"

int					ft_ch_map(char c)
{
	if (c >= 48 && c <= 57)
		return (1);
	if (c == '.')
		return (1);
	if (c == 'x' || c == 'X')
		return (1);
	if (c == 'o' || c == 'O')
		return (1);
	if (c == ' ')
		return (1);
	return (0);
}

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

int					ft_read(char **line)
{
	if (!get_next_line(0, line))
	{
		ft_strdel(line);
		return (0);
	}
	return (1);
}

char				*ft_get_size(unsigned char *x, unsigned char *y, int s)
{
	char *line;

	if (!ft_read(&line))
		return (NULL);
	*x = ft_atoi(&line[s]);
	*y = ft_atoi(&line[s + ft_num_len(*x) + 1]);
	if (s != 8)
		ft_strdel(&line);
	return (line);
}

void				ft_out(char *line, int ch)
{
	if (ch == 1)
	{
		write(1, line, ft_strlen(line));
		write(1, "\n", 1);
	}
	ft_strdel(&line);
}
