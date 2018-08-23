/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshata <tshata@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 15:52:54 by tshata            #+#    #+#             */
/*   Updated: 2018/08/23 16:47:27 by tshata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	get_map(t_filler *f, int fd, char **line)
{
	int		y;
	
	y = 0;
	f->map_y = ft_atoi(*line + 8);
	f->map_x = ft_atoi(*line + 11);
	ft_strdel(line);
	get_next_line(fd, line);
	ft_strdel(line);
	if (!(f->map = (char **)ft_memalloc(sizeof(char *) * f->map_y)))
		return ;
	while (y < f->map_y)
	{
		get_next_line(fd, line);
		f->map[y] = ft_strdup(*line + 4);
		y++;
		ft_strdel(line);
	}
	get_token(f, fd);
}
