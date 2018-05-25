/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viz.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltkache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 18:16:12 by oltkache          #+#    #+#             */
/*   Updated: 2018/04/26 18:16:13 by oltkache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __VIZ_H
# define __VIZ_H

# include "../libft/get_next_line.h"
# include <unistd.h>
# include <stdio.h>

int					ft_read(char **line);
char				*ft_get_size(unsigned char *x, unsigned char *y, int s);
void				ft_out(char *line, int ch);

#endif
