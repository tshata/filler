/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dist.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshata <tshata@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 14:45:00 by tshata            #+#    #+#             */
/*   Updated: 2018/08/25 16:54:07 by tshata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include "../libft/libft.h"
/*
static int	place_small2(t_filler *f, int l, int m)
{
	while(l < f->map_y - f->trim_token_y)
	{
		while(m < f->map_y - f->trim_token_y)
		{
			if(check_overlap(f, l + 1, m + 1))
			{
				choose_move(f, l + 1, m +1);
				//return (1);
			}
			m++;
		}
		l++;
	}
//	place(f, i, j);
	return (0);
}
*/
static void	place_mid2(t_filler *f, int l, int m)
{
	int i;
	int j;

	i = l;
	j = m;
	l++;
	m++;
	while(l < f->map_y - f->trim_token_y)
	{
		while(m < f->map_y - f->trim_token_y)
		{
			if(check_overlap(f, l, m))
			{
				choose_move(f, l, m);
				return ;
			}
			m++;
		}
		l++;
	}
	place(f, i, j);
	return ;
}

void		choose_move(t_filler *f, int l, int m)
{
	if (f->me == 'x' && f->map_y == 24)
		place(f, l, m);
	else if (f->me == 'o' && f->map_y == 24)
		place_mid2(f, l, m);
	else if (f->me == 'x' && f->map_y == 15)
		place(f, l, m);
	else if (f->me == 'o' && f->map_y == 15)
		place_mid2(f, l, m); 
	else
		place(f, l, m);
}
