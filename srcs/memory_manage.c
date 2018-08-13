/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_manage.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshata <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 15:15:19 by tshata            #+#    #+#             */
/*   Updated: 2018/08/13 15:12:41 by tshata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void		matrix_free(char **matrix, int y)
{
	int	i;
	char	**map;

	i = 0;
	map = matrix;
	while (i < y)
	{
		ft_strdel(&map[i]);
		i++;
	}
	free(matrix);
	matrix = NULL;
}

void		memory_manage(t_filler *filler)
{
	matrix_free(filler->map, filler->map_y);
	matrix_free(filler->token, filler->token_y);
	filler->play->coords[0] = 0;
	filler->play->coords[1] = 0;
	filler->play->dst = 20000000;
	filler->token_y = 0;
	filler->token_x = 0;
	filler->map_y = 0;
	filler->map_x = 0;
	filler->off[0] = 0;
	filler->off[1] = 0;
	filler->off[2] = 0;
	filler->off[3] = 0;
	filler->play->place = 0;
}
