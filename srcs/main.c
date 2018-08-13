/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshata <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 09:43:35 by tshata            #+#    #+#             */
/*   Updated: 2018/08/13 16:39:09 by tshata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/filler.h"

int				main(void)
{
	t_filler	*filler;
	char		*line;

	line = NULL;
	filler = init_filler();
	read_player(filler);
	while (1)
	{
		get_next_line(0, &line);
		get_map(filler, line);
		ft_strdel(&line);
		get_token(filler);
		moves(filler);
		place(filler);
		memory_manage(filler);
		if (filler->game_over == 1)
			break;
	}
	return (0);
}
