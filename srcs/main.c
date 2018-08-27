/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshata <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 09:43:35 by tshata            #+#    #+#             */
/*   Updated: 2018/08/27 09:36:07 by tshata           ###   ########.fr       */
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
	line = NULL;
	f = init_filler();
	read_player(f, fd);
	while (1)
	{
		if (!get_next_line(fd, &line))
			return (0);
		get_map(f, fd, &line);
		get_trim_token(f);
		if (!moves(f))
		{
			ft_putendl("0 0");
			return (0);
		}
		memory_manage(f);
	}
	return (0);
}
