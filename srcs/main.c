/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshata <tshata@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 09:43:35 by tshata            #+#    #+#             */
/*   Updated: 2018/08/23 17:29:32 by tshata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "../includes/filler.h"

int	main(void)
{
	t_filler	*f;
	char		*line;
	int			fd;

	fd = 0;
//	fd = open("./sample_maps/fuckedup.txt", O_RDONLY);
	line = NULL;
	f = init_filler();
	read_player(f, fd);
	while (1)
	{
		if (get_next_line(fd, &line) == 0)
			break ;
		get_map(f, fd, &line);
		get_trim_token(f);
//		printcut(f);
		moves(f);
//		memory_manage(f);
//		if (f->game_over == 1)
//			break ;
		
	}
	return (0);
}
