/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshata <tshata@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 15:52:43 by tshata            #+#    #+#             */
/*   Updated: 2018/08/27 09:34:33 by tshata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	get_token(t_filler *f, int fd)
{
	int		y;
	char	*line;

	line = NULL;
	get_next_line(fd, &line);
	f->token_y = ft_atoi(&line[6]);
	f->token_x = ft_atoi(&line[8]);
	if (!(f->token = (char **)ft_memalloc(sizeof(char *) * f->token_y)))
		return ;
	y = 0;
	while (y < f->token_y)
	{
		get_next_line(fd, &line);
		f->token[y] = line;
		y++;
	}
	calculate_offset(f);
}

void	get_trim_token(t_filler *f)
{
	int		y;

	f->trim_token_y = f->token_y - f->off[3] - f->off[1];
	f->trim_token_x = f->token_x - f->off[0] - f->off[2];
	if (!(f->trim_token = (char **)ft_memalloc(sizeof(char *) *
					f->trim_token_y)))
		return ;
	y = f->off[1];
	while (y < f->token_y - f->off[3])
	{
		f->trim_token[y - f->off[1]] = ft_strsub(f->token[y], f->off[0],
				f->trim_token_x);
		y++;
	}
}
