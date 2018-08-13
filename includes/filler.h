/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshata <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 09:55:27 by tshata            #+#    #+#             */
/*   Updated: 2018/08/13 09:40:31 by tshata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FILLER_H
# define FILLER_H

# include "../libft/libft.h"

typedef struct	s_play
{
	int			place;
	int			dst;
	int			*coords;
}				t_plays;

typedef	struct	s_filler
{
	char 		me;
	char		enemy;
	int			map_x;
	int			map_y;
	int			token_x;
	int 		token_y;
	int			put_x;
	int			put_y;
	int			off[4];
	char		**map;
	char		**token;
	int			game_over;
	t_plays		*play;
}				t_filler;

void		memory_manage(t_filler *filler);
void		choose_move(t_filler *filler, int l, int m);
void		get_map(t_filler *filler, char *str);
void		read_player(t_filler *filler);
t_filler	*init_filler();
int 		pythagoras(int l, int m, int *coords);
int 		dst(t_filler *filler, int l, int m);
void		compare_dst(t_filler * filler, int l, int m);
void		get_token(t_filler *filler);
void		moves(t_filler *filler);
void		place(t_filler *filler);
void		check_avail(t_filler *filler, int l, int m);
void		calculate_offset(t_filler *filler);
#endif
