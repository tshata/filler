/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dist.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshata <tshata@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 14:45:00 by tshata            #+#    #+#             */
/*   Updated: 2018/08/22 16:56:19 by tshata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include "../libft/libft.h"

int		pythagoras(int l, int m, int *coords)
{
	return (ft_sqr((l - coords[0]) + (m - coords[1])));
}

int		dst(t_filler *f, int l, int m)
{
	int	coords[3];

	coords[2] = 2000000000;
	coords[0] = 0;
	while (coords[0] < f->play->coords[0] - (f->off[1] + f->off[3]))
	{
		coords[1] = 0;
		while (coords[1] < f->play->coords[1] - (f->off[0] + f->off[2]))
		{
			if (ft_tolower(f->map[coords[0]][coords[1]]) == f->me)
				coords[2] = pythagoras(l, m, coords);
			coords[1] += 1;
		}
		coords[0] += 1;
	}
	return (coords[2]);
}

void	choose_move(t_filler *f, int l, int m)
{
	if (f->play->dst > dst(f, l, m))
	{
		f->play->coords[0] = l;
		f->play->coords[1] = m;
		f->play->dst = (dst(f, l, m));
	}
	else
	{
		f->play->coords[0] = l;
		f->play->coords[1] = m;
	}
	place(f);
}
