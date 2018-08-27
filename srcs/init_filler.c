/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_filler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshata <tshata@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 15:47:40 by tshata            #+#    #+#             */
/*   Updated: 2018/08/27 09:35:20 by tshata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void		read_player(t_filler *f, int fd)
{
	int		i;
	char	*line;

	i = 0;
	line = NULL;
	get_next_line(fd, &line);
	while (!ft_isdigit(line[i]) && line[i])
		i++;
	if (line[i] == '1')
	{
		f->me = 'o';
		f->enemy = 'x';
	}
	else
	{
		f->me = 'x';
		f->enemy = 'o';
	}
	ft_strdel(&line);
}

t_filler	*init_filler(void)
{
	t_filler *f;

	f = (t_filler *)ft_memalloc(sizeof(t_filler));
	f->map = NULL;
	f->token = NULL;
	f->trim_token = NULL;
	f->game_over = 0;
	f->off[0] = 0;
	f->off[1] = 0;
	f->off[2] = 0;
	f->off[3] = 0;
	f->play = ft_memalloc(sizeof(t_plays));
	f->play->place = 0;
	f->play->dst = 20000000;
	return (f);
}
