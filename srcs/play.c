/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshata <tshata@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 12:34:56 by tshata            #+#    #+#             */
/*   Updated: 2018/08/27 11:03:48 by tshata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

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
	int		temp;
	int		pos[3];

	temp = x;
	pos[2] = 0;
	pos[0] = 0;
	while (pos[0] < f->trim_token_y)
	{
		pos[1] = 0;
		x = temp;
		while (pos[1] < f->trim_token_x)
		{
			if (f->trim_token[pos[0]][pos[1]] == '*')
			{
				pos[2] += (on_my_terr(f, y, x)) ? 1 : 0;
				if (on_en_terr(f, y, x))
					return (0);
			}
			x++;
			pos[1] += 1;
		}
		pos[0] += 1;
		y++;
	}
	return (pos[2] == 1 ? 1 : 0);
}

int			best_move(t_filler *f, t_moves *head)
{
	int	max;
	int	pos[2];

	max = 2147483647;
	if (head == NULL)
		return (0);
	else
	{
		while (head)
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
	place(f, pos[0], pos[1]);
	return (1);
}

int			moves(t_filler *f)
{
	int		y;
	int		x;
	t_moves	*head;

	head = NULL;
	y = 0;
	while (y <= f->map_y - f->trim_token_y)
	{
		x = 0;
		while (x <= f->map_x - f->trim_token_x)
		{
			if (check_overlap(f, y, x))
			{
				if (f->map_y == 100)
				{
					place(f, y, x);
					return (1);
				}
				push_back(&head, new_node(y, x));
			}
			x++;
		}
		y++;
	}
	return (best_move(f, head)) > 0 ? 1 : 0;
}
