/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshata <tshata@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 12:34:56 by tshata            #+#    #+#             */
/*   Updated: 2018/08/23 17:39:34 by tshata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	place(t_filler *f)
{
	if (f->play->place == 1)
	{
		ft_putnbr(f->play->coords[0] + f->off[1]);
		ft_putchar(' ');
		ft_putnbr(f->play->coords[1] + f->off[0]);
		ft_putchar('\n');
	}
	else
	{
		ft_putendl("0 0");
		f->game_over = 1;
	}
}

static	int	on_my_terr(t_filler *f, int y, int x)
{
	if (ft_tolower(f->map[y][x]) == f->me)
		return (1);
	return (0);
}

static	int	on_en_terr(t_filler *f, int y, int x)
{
	if (ft_tolower(f->map[y][x]) == f->enemy)
		return (1);
	return (0);
}

int 	check_overlap(t_filler *f, int y, int x)
{
	int i;
	int j;
	int	overlap;
	int	temp;

	temp = x;
	overlap = 0;
	i = 0;
	while(i < f->trim_token_y)
	{
		j = 0;
		x = temp;
		while (j < f->trim_token_x)
		{
			if (f->trim_token[i][j] == '*')
			{
				if (on_my_terr(f, y, x))
					overlap++;
				else if (on_en_terr(f, y, x))
					return (0);
			}
			j++;
			x++;
			if (overlap > 1)
				return (0);
		}
		i++;
		y++;
	}
	return (overlap == 1 ? 1 : 0);
}

int		moves(t_filler *f)
{
	int y;
	int x;
	
	y = 0;
	while (y <= f->map_y - f->trim_token_y)
	{
		x = 0;
		while (x <= f->map_x - f->trim_token_x)
		{
			if (check_overlap(f, y, x))
			{
				ft_putnbr(y - f->off[1]);
			  	ft_putchar(' ');
				ft_putnbr(x - f->off[0]);
				ft_putchar('\n');
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}
