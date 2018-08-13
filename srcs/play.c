/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshata <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 12:34:56 by tshata            #+#    #+#             */
/*   Updated: 2018/08/13 17:00:48 by tshata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	place(t_filler *filler)
{
	if (filler->play->place == 1)
	{
		ft_putnbr(filler->play->coords[0]);
		ft_putchar(' ');
		ft_putnbr(filler->play->coords[1]);
		ft_putchar('\n');
	}
	else
	{
		ft_putendl("0 0");
		filler->game_over = 1;
	}
}
void 	check_avail(t_filler *filler, int y, int x)
{
	int i;
	int j;
	int k;

	j = 0;
	k = 0;
	while (j < filler->token_y - (filler->off[1] + filler->off[3]))
	{
		i = 0;
		while (i < filler->token_x - (filler->off[0] + filler->off[2]))
		{
			if (ft_tolower(filler->map[y + j][x + i]) == filler->me && (
					filler->token[j + filler->off[1]][i + filler->off[0]] == '*'))
			{
				k++;
		
			}
			else if (ft_tolower(filler->map[y + j][x + i]) == filler->enemy &&
					filler->token[j + filler->off[1]][i + filler->off[0]] == '*')
				k += 2;
			i++;
		}
		j++;
	}
/*	if (k == 1)
	{
		filler->play->place = 1;
		choose_move(filler, y, x);
	}
	 if (j == filler->token_y || k == 0)
	{
		k = 0;
	while (j > 0)
	{
	//	i = filler->token_x ;
		while (i > 0)
		{
			if (ft_tolower(filler->map[y + j][x + i]) == filler->me && (
					filler->token[j + filler->off[1]][i + filler->off[0]] == '*'))
			{
				k++;
			}
			if (ft_tolower(filler->map[y + j][x + i]) == filler->enemy &&
					filler->token[j + filler->off[1]][i + filler->off[0]] == '*')
				k += 2;
			i--;
		}
		j--;
	}
	}*/
	if (k == 1)
	{	
		filler->play->place = 1;
		choose_move(filler, y, x);
	}
}

void	moves(t_filler *filler)
{
	int y;
	int x;

	y = 0;
	while (y + (filler->token_y - (filler->off[1] + filler->off[3])) < filler->map_y )
	{
		x = 0;
		while(x + (filler->token_x - (filler->off[0] + filler->off[2])) < filler->map_x )
		{
			check_avail(filler, y, x);
			x++;
		}
		y++;
	}
}
