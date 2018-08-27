/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshata <tshata@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 14:45:00 by tshata            #+#    #+#             */
/*   Updated: 2018/08/27 09:31:32 by tshata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include "../libft/libft.h"

int		pythagoras(int y, int x, int *coords)
{
	return (ft_sqr((y - coords[0]) + (x - coords[1])));
}

int		dst(t_filler *f, int y, int x)
{
	int	coords[3];

	coords[2] = 20000000;
	coords[0] = 0;
	while (coords[0] < f->map_y - f->off[1] - f->off[3])
	{
		coords[1] = 0;
		while (coords[1] < f->map_x - f->off[0] - f->off[2])
		{
			if (ft_tolower(f->map[coords[0]][coords[1]]) == f->enemy)
				coords[2] = pythagoras(y, x, coords);
			coords[1] += 1;
		}
		coords[0] += 1;
	}
	return (coords[2]);
}
