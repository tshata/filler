/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshata <tshata@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 12:34:56 by tshata            #+#    #+#             */
/*   Updated: 2018/08/25 16:52:33 by tshata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void		place(t_filler *f, int y, int x)
{
	ft_putnbr(y - f->off[1]);
	ft_putchar(' ');
	ft_putnbr(x - f->off[0]);
	ft_putchar('\n');
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

int			check_overlap(t_filler *f, int y, int x)
{
	int i;
	int j;
	int	overlap;
	int	temp;

	temp = x;
	overlap = 0;
	i = 0;
	while (i < f->trim_token_y)
	{
		j = 0;
		x = temp;
		while (j < f->trim_token_x)
		{
			if (f->trim_token[i][j] == '*')
			{
				overlap += (on_my_terr(f, y, x)) ? 1 : 0;
				if (on_en_terr(f, y, x))
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

int			best_move(t_filler *f, t_moves *head)
{
	int 	max;
	int	pos[2];

	max = 2147483647;
	if (head == NULL)
		return (0);
	else
	{
		while(head)
		{
			if (dst(f, head->y, head->x) < max)
			{
				max = dst(f, head->y, head->x);
				pos[0] = head->y;
				pos[1] = head->x;
			}
			head = head->next;
		}
	}
	ft_putnbr(pos[0] - f->off[1]);
	ft_putchar(' ');
	ft_putnbr(pos[1] - f->off[0]);
	ft_putchar('\n');
	return (1);
}
int			moves(t_filler *f)
{
	int y;
	int x;
	t_moves *head;


	head = NULL;
	y = 0;
	while (y <= f->map_y - f->trim_token_y)
	{
		x = 0;
		while (x <= f->map_x - f->trim_token_x)
		{
			if (check_overlap(f, y, x))
			{
				if (f->me == 'x' && (f->map_y != 100)) 
				{
					first_move(f, y, x);
					return (1);
				}
				push_back(&head, new_node(y, x)); 
			}
			x++;
		}
		y++;
	}
	if (best_move(f, head))
		return (1);
	return (0);
}
