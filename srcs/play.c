/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshata <tshata@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 12:34:56 by tshata            #+#    #+#             */
/*   Updated: 2018/08/22 17:03:59 by tshata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	place(t_filler *f)
{
	if (f->play->place == 1)
	{
		ft_putnbr(f->play->coords[0]);
		ft_putchar(' ');
		ft_putnbr(f->play->coords[1]);
		ft_putchar('\n');
	}
	else
	{
		ft_putendl("0 0");
		f->game_over = 1;
	}
}
int 	check_avail(t_filler *f, int y, int x)
{
	int i;
	int j;
	int k;

	j = 0;
	k = 0;
	while (j < f->trim_token_y)
	{		

			i = 0;
		while (i < f->trim_token_x)
		{
			if (y + x < 10)
				k++;
			else if (y + x < 10)
				k += 10;
			i++;
		}
		j++;
	}
	if (k == 1)
	{	
		f->play->place = 1;
		return (1);
	}
	else
		return (0);
}

void	moves(t_filler *f)
{
	int y;
	int x;

	y = 0;
	while (y + f->token_y  < f->map_y)
	{
		x = 0 ;
		while(x + f->token_x < f->map_x)
		{
		if(check_avail(f, y, x))
				choose_move(f, y, x);
			x++;
		}
		y++;
	}
}
