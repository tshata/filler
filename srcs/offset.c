/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   offset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshata <tshata@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 14:57:03 by tshata            #+#    #+#             */
/*   Updated: 2018/08/22 17:06:28 by tshata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

/*
** the offset is handled clockwise.
** off[0] = left.
** off[1] = top.
** off[2] = right.
** off[3] = bottom.
*/

void		top_offset(t_filler *f)
{
	int	dim[2];
	int	count;
	int	end;

	dim[0] = 0;
	count = 0;
	end = 0;
	while (dim[0] < f->token_y)
	{
		dim[1] = 0;
		while (dim[1] < f->token_x)
		{
			if (f->token[dim[0]][dim[1]] == '*')
			{
				end = 1;
				break ;
			}
			dim[1] += 1;
		}
		if (end)
			break ;
		count++;
		dim[0] += 1;
	}
	f->off[1] = count;
}

void		bottom_offset(t_filler *f)
{
	int	dim[2];
	int	count;
	int	end;

	dim[0] = f->token_y - 1;
	count = 0;
	end = 0;
	while (dim[0] > 0)
	{
		dim[1] = 0;
		while (dim[1] < f->token_x)
		{
			if (f->token[dim[0]][dim[1]] == '*')
			{
				end = 1;
				break ;
			}
			dim[1] += 1;
		}
		if (end)
			break ;
		count++;
		dim[0] -= 1;
	}
	f->off[3] = count;
}

void		right_offset(t_filler *f)
{
	int	dim[2];
	int	count;
	int	end;

	dim[1] = f->token_x - 1;
	count = 0;
	end = 0;
	while (dim[1] > 0)
	{
		dim[0] = 0;
		while (dim[0] < f->token_y)
		{
			if (f->token[dim[0]][dim[1]] == '*')
			{
				end = 1;
				break ;
			}
			dim[0] += 1;
		}
		if (end)
			break ;
		count++;
		dim[1] -= 1;
	}
	f->off[2] = count;
}

void		left_offset(t_filler *f)
{
	int	dim[2];
	int	count;
	int	end;

	dim[1] = 0;
	count = 0;
	end = 0;
	while (dim[1] < f->token_x)
	{
		dim[0] = 0;
		while (dim[0] < f->token_y)
		{
			if (f->token[dim[0]][dim[1]] == '*')
			{
				end = 1;
				break ;
			}
			dim[0] += 1;
		}
		if (end)
			break ;
		count++;
		dim[1] += 1;
	}
	f->off[0] = count;
}

void		calculate_offset(t_filler *f)
{
	top_offset(f);
	bottom_offset(f);
	right_offset(f);
	left_offset(f);
}
