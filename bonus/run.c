/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltkache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 19:31:18 by oltkache          #+#    #+#             */
/*   Updated: 2018/05/03 19:31:19 by oltkache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/get_next_line.h"

int		main(void)
{
	char	*line;

	get_next_line(0, &line);
	write(1, line, ft_strlen(line));
	write(1, "\n", 1);
	ft_strdel(&line);
	while (get_next_line(0, &line))
	{
		if (line[0] == '=' && line[1] == '=')
		{
			write(1, line, ft_strlen(line));
			write(1, "\n", 1);
		}
		if (line[0] == 'p' && line[3] == '-')
		{
			write(1, line, ft_strlen(line));
			write(1, "\n", 1);
		}
		ft_strdel(&line);
	}
	return (0);
}
