/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshata <tshata@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 09:43:35 by tshata            #+#    #+#             */
/*   Updated: 2018/08/22 17:43:49 by tshata           ###   ########.fr       */
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
	fd = open("./test.txt", O_RDONLY);
	line = NULL;
	f = init_filler();
	read_player(f, fd);
	while (1)
	{
		get_map(f, fd);
		get_trim_token(f, fd);
		moves(f);
		memory_manage(f);
		if (f->game_over == 1)
			break ;
	}
	return (0);
}
