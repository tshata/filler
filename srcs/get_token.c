/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshata <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 15:52:43 by tshata            #+#    #+#             */
/*   Updated: 2018/08/10 15:17:15 by tshata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
void	 get_token(t_filler *filler)
{
	int y;
	char *line;	

	line = NULL;
	get_next_line(0, &line);
	filler->token_y = ft_atoi(&line[6]);
	filler->token_x = ft_atoi(&line[8]);
	if (!(filler->token = (char **)ft_memalloc(sizeof(char **) * filler->token_y)))
		return ;
	y = 0;
	while ((y < filler->token_y))
	{
		get_next_line(0, &line);
		filler->token[y] = line;
		y++;
		if (y == filler->token_y)
			break;
	}
	calculate_offset(filler);
}
