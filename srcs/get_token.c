/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshata <tshata@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 15:52:43 by tshata            #+#    #+#             */
/*   Updated: 2018/08/22 17:48:19 by tshata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	get_token(t_filler *f, int fd)
{
	int		y;
	char	*line;

	line = NULL;
	while (get_next_line(fd, &line))
		if (ft_strstr(line, "Piece"))
			break ;
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

void	get_trim_token(t_filler *f, int fd)
{
	int		y;
	char	*line;
	
	line = NULL;
	while(get_next_line(fd, &line))
		if(ft_strstr(line, "Piece"))
			break;
	if (!(f->trim_token = (char **)ft_memalloc(sizeof(char *) * f->token_y - f->off[1] + f->off[3])))
		return ;
	y = 0;
	y = y + f->off[1];
	while (y < f->token_y - f->off[3])
	{
		get_next_line(fd, &line);
		f->trim_token[y] = ft_strsub(line, f->off[0], f->token_x - f->off[2]);
		ft_putstr(f->trim_token[y]);
		y++;
	}
}
