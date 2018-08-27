/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshata <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 12:16:49 by tshata            #+#    #+#             */
/*   Updated: 2018/08/27 11:03:59 by tshata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

t_moves		*new_node(int y, int x)
{
	t_moves *ptr;

	if (!(ptr = (t_moves *)ft_memalloc(sizeof(t_moves))))
		return (0);
	else
	{
		ptr->y = y;
		ptr->x = x;
		ptr->next = NULL;
	}
	ptr->y = y;
	ptr->x = x;
	ptr->next = NULL;
	return (ptr);
}

void		push_back(t_moves **head, t_moves *node)
{
	t_moves *current;

	current = *head;
	if (*head == NULL)
		*head = node;
	else
	{
		while (current->next)
			current = current->next;
		current->next = node;
	}
}

void		place(t_filler *f, int y, int x)
{
	ft_putnbr(y - f->off[1]);
	ft_putchar(' ');
	ft_putnbr(x - f->off[0]);
	ft_putchar('\n');
}
