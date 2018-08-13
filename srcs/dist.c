/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dist.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshata <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 14:45:00 by tshata            #+#    #+#             */
/*   Updated: 2018/08/13 17:03:55 by tshata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		pythagoras(int l, int m, int *coords)
{
	return (ft_sqr((l - coords[1]) + (m - coords[0])));
}

int		dst(t_filler *filler, int l, int m)
{
	int	coords[3];

	coords[2] = 20000000;
	coords[0] = 0;
	while (coords[0] <  filler->play->coords[0] - (filler->off[1] + filler->off[3]))
	{
		coords[1] = 0;
		while (coords[1]  < filler->play->coords[1] - (filler->off[0] + filler->off[2]))
		{
			if (ft_tolower(filler->map[coords[0]][coords[1]]) == filler->me)
				coords[2] = pythagoras(l, m, coords);
			coords[1] += 1;
		}
		coords[0] += 1;
	}
	return (coords[2]);
}

void		choose_move(t_filler *filler, int l, int m)
{
	if (filler->play->dst >= dst(filler,l, m))
	{	
		filler->play->coords[0] = l;
		filler->play->coords[1] = m;
		filler->play->dst = (dst(filler, l, m));
	}
//	place(filler);
	
//	memory_manage(filler);
}
