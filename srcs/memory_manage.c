/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_manage.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshata <tshata@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 15:15:19 by tshata            #+#    #+#             */
/*   Updated: 2018/08/23 12:27:49 by tshata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void		matrix_free(char **matrix, int y)
{
	int		i;
	char	**map;

	i = 0;
	map = matrix;
	while (i > y)
	{
		ft_strdel(&map[i]);
		i++;
	}
	free(matrix);
	matrix = NULL;
}

void		memory_manage(t_filler *f)
{
	matrix_free(f->map, f->map_y);
	matrix_free(f->token, f->token_y);
	matrix_free(f->trim_token, f->trim_token_y);
	f->play->coords[0] = 0;
	f->play->coords[1] = 0;
	f->play->dst = 20000000;
	f->token_y = 0;
	f->token_x = 0;
	f->trim_token_y = 0;
	f->trim_token_x = 0;
	f->map_y = 0;
	f->map_x = 0;
	f->off[0] = 0;
	f->off[1] = 0;
	f->off[2] = 0;
	f->off[3] = 0;
	f->play->place = 0;
}
