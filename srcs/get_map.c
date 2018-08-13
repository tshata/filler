/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshata <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 15:52:54 by tshata            #+#    #+#             */
/*   Updated: 2018/08/10 15:17:32 by tshata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	 get_map(t_filler *filler, char *str)
{
	int y;
	char *line;	

	y = 0;
	line = NULL;
	filler->map_y = ft_atoi(&str[8]);
	filler->map_x = ft_atoi(&str[11]);
	if (!(filler->map = (char **)ft_memalloc(sizeof(char **) * filler->map_y)))
		return ;
	get_next_line(0, &line);
	ft_strdel(&line);
	while(y < filler->map_y)
	{
		get_next_line(0, &line);
		filler->map[y] = ft_strdup(line + 4);
		y++;
	}
}
