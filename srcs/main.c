/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshata <tshata@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 09:43:35 by tshata            #+#    #+#             */
/*   Updated: 2018/08/23 17:42:25 by tshata           ###   ########.fr       */
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
		if (!get_next_line(fd, &line))
			return (0);
		get_map(f, fd, &line);
		get_trim_token(f);
//		printcut(f);
		if (!moves(f))
		{
			ft_putendl("0 0");
			return (0);
		}
//		memory_manage(f);
//		if (f->game_over == 1)
//			break ;
		
	}
	return (0);
}
