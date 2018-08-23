/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshata <tshata@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 09:55:27 by tshata            #+#    #+#             */
/*   Updated: 2018/08/23 16:46:33 by tshata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/libft.h"

typedef struct	s_play
{
	int			place;
	int			dst;
	int			coords[3];
}				t_plays;

typedef	struct	s_filler
{
	char		me;
	char		enemy;
	int			map_x;
	int			map_y;
	int			token_x;
	int			token_y;
	int			trim_token_y;
	int			trim_token_x;
	int			off[4];
	char		**map;
	char		**token;
	char		**trim_token;
	int			game_over;
	t_plays		*play;
}				t_filler;

void			memory_manage(t_filler *f);
void			choose_move(t_filler *f, int l, int m);
void			get_map(t_filler *f, int fd,char **line);
void			read_player(t_filler *f, int fd);
t_filler		*init_filler();
int				pythagoras(int l, int m, int *coords);
int				dst(t_filler *f, int l, int m);
void			compare_dst(t_filler *f, int l, int m);
void			get_token(t_filler *f, int fd);
void			get_trim_token(t_filler *f);
void			moves(t_filler *f);
void			place(t_filler *f);
long long		ft_sqr(int n);
void			printcut(t_filler *f);
int				check_overlap(t_filler *f, int l, int m);
void			calculate_offset(t_filler *f);
#endif
